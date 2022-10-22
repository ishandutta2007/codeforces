#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define IL inline
#define rint register int
#define ll long long 
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
    return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T> void read(T &x)
{
    rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
    while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f; 
}
char sr[1<<24],z[20]; ll Z,C1=-1;
template<class T>void wer(T x)
{
    if (x<0) sr[++C1]='-',x=-x;
    while (z[++Z]=x%10+48,x/=10);
    while (sr[++C1]=z[Z],--Z);
}
IL void wer1()
{
    sr[++C1]=' ';
}
IL void wer2()
{
	sr[++C1]='\n';
}
const int N=2e6;
int a[N],f[N],p[N],n;
int sum[N];
#define lowbit(x) (x&(-x))
void change(int x)
{
	while (x>=1)
	{
		sum[x]++;
		x-=lowbit(x);
	}
}
int query(int x)
{
	int ans=0;
	while (x<=n)
	{
		ans+=sum[x];
		x+=lowbit(x);
	}
	return ans;
}
stack<int> q;
set<int> S;
int main()
{
	int T;
	cin>>n;
	int cnt=0;
	rep(i,1,2*n)
	{
		char c;
		cin>>c;
		if (c=='+')
		{
			a[i]=-1; cnt++;
		} else
		{
			int t;
			cin>>t;
			a[i]=t; cnt--;
		}
		f[i]=cnt;
		if (cnt<0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
/*	dep(i,2*n,1)
	{
		if (a[i]>0)
		{
			if (query(a[i])<f[i])
			{
				cout<<"NO"<<endl;
				return 0;
			}
			change(a[i]);
	    }
	} */
	cnt=0;
	rep(i,1,2*n)
	{
		if (a[i]==-1)
		{ 
		  cnt++;
		  q.push(cnt);
	    } else
	    {
	    	int x=q.top(); q.pop(); 
	    	p[x]=a[i];
	    }
	}
	cnt=0;
	rep(i,1,2*n)
	{
		if (a[i]==-1)
		{
		  cnt++;
		  S.insert(p[cnt]);	
		} else
		{
			set<int>::iterator it=S.begin();
			if (*it!=a[i])
			{
				cout<<"NO"<<endl;
				return 0;
			}
			S.erase(it);
		}
	}
	cout<<"YES"<<endl;
	rep(i,1,n) cout<<p[i]<<" ";
//	fwrite(sr,1,C1+1,stdout);
	return 0;
}