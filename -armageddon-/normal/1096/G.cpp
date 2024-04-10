#include<bits/stdc++.h>
//#include <self/fft>
#include <algorithm>
using namespace std;
const int N=2500*1000+555;
const int LOGN=22;
int g=3;//g 998244353  
const int mod=998244353;

inline int mul(int a,int b){
	return int(1LL*a*b%mod);
}

inline int norm(int a) {
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}

inline int ksm(int basic,int x)
{
	int res=1;
	while(x)
	{
		if(x&1)
		{
			res=mul(res,basic);
		}
		x>>=1;
		basic=mul(basic,basic);
	}
	return res;
}

inline int inv(int a)
{
	return ksm(a,mod-2);
}

vector<int> w[LOGN];
vector<int> rv[LOGN];

void precalc()
{
    int wb=ksm(g,(mod-1)/(1<<LOGN));
    for(int st=0;st<LOGN-1;st++)
	{
        w[st].assign(1<<st,1);
        int bw=ksm(wb,1<<(LOGN-st-1));
        int cw=1;
        for (int k=0;k<(1<<st);k++)
		{
            w[st][k]=cw;
            cw=mul(cw,bw);
        }
    }
    for(int st=0;st<LOGN;st++)
	{
        rv[st].assign(1 << st, 0);
        if(st == 0)
		{
            rv[st][0] = 0;
            continue;
        }
        int h=(1<<(st-1));
        for(int k=0;k<(1<<st);k++)
        {
        	rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
		}
    }
}

inline void fft(int a[N],int n,bool inverse)
{
    int ln=0;
    while((1<<ln)<n) ln++;
    n=(1<<ln);
    for(int i=0;i<n;i++)
    {
        int ni=rv[ln][i];
        if(i<ni)
        {
        	swap(a[i], a[ni]);
		}
    }
    for(int st=0;(1<<st)<n;st++)
	{
        int len=(1<<st);
        for(int k=0;k<n;k+=(len<<1))
		{
            for(int pos=k;pos<k+len;pos++)
			{
                int l=a[pos];
                int r=mul(a[pos+len],w[st][pos-k]);
                a[pos]=norm(l+r);
                a[pos+len]=norm(l-r);
            }
        }
    }
    if(inverse)
	{
        int in=inv(n);
        for(int i=0;i<n;i++)
        {
        	a[i]=mul(a[i],in);
		}
        reverse(a+1,a+n);
    }
}

int aa[N],bb[N],cc[N];

inline vector<int> multiply(const vector<int> a,const vector<int> b)
{
	int ln=1;
	while(ln<(a.size()+b.size())) ln<<=1;
	for(int i=0;i<ln;i++)
	{
		aa[i]=(i<a.size()?a[i]:0);
	}
	for(int i=0;i<ln;i++)
	{
		bb[i]=(i<b.size()?b[i]:0);
	}
	fft(aa,ln,false);
	fft(bb,ln,false);
	for(int i=0;i<ln;i++)
	{
		cc[i]=mul(aa[i],bb[i]);
	}
	fft(cc,ln,true);
	vector<int> c(ln,0);
	for(int i=0;i<c.size();i++)
	{
		c[i]=cc[i];
	}
	while(c.size()>1 && c.back()==0) c.pop_back();
	return c;
}

int main()
{
	precalc();
	int a[10]={0};
	int n,k;
	cin>>n>>k;
	vector <int> basic;
	int x;
	for(int i=0;i<k;i++)
	{
		cin>>x;
		a[x]++;
	}
	for(int i=0;i<=9;i++)
	{
		basic.push_back(a[i]);
	}
	vector <int> res={1};
	n=n/2;
	while(n)
	{
		if(n&1)
		{
			res=multiply(res,basic);
		}
		basic=multiply(basic,basic);
		n>>=1;
	}
	int resa=0;
	for(int i=0;i<res.size();i++)
	{
//		cout<<res[i]<<' ';
		resa+=(1LL*res[i]*res[i])%mod;
		resa%=mod;
	}
	cout<<resa<<endl;
}