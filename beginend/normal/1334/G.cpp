#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N=200005;
const double pi=acos(-1);

struct com
{
    double x,y;
    com operator + (const com &d) const {return (com){x+d.x,y+d.y};}
    com operator - (const com &d) const {return (com){x-d.x,y-d.y};}
    com operator * (const com &d) const {return (com){x*d.x-y*d.y,x*d.y+y*d.x};}
    com operator / (const double &d) const {return (com){x/d,y/d};}
}A[N*4],B[N*4],m1[26],m2[26];

int n,m,rev[N*4],L,col[26],per[26],ans[N];
char s[N],t[N];

void pre()
{
	int lg=0;
	for (L=1;L<n+m;L<<=1,lg++);
	for (int i=0;i<L;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
}

void FFT(com *a,int f)
{
    for (int i=0;i<L;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int i=1;i<L;i<<=1)
    {
        com wn=(com){cos(pi/i),f*sin(pi/i)};
        for (int j=0;j<L;j+=(i<<1))
        {
            com w=(com){1,0};
            for (int k=0;k<i;k++)
            {
                com u=a[j+k],v=a[j+k+i]*w;
                a[j+k]=u+v;a[j+k+i]=u-v;
                w=w*wn;
            }
        }
    }
    if (f==-1) for (int i=0;i<L;i++) a[i]=a[i]/L;
}

void init()
{
	for (int i=0;i<26;i++) scanf("%d",&per[i]),per[i]--;
	int tot=0;
	for (int i=0;i<26;i++)
	{
		if (col[i]) continue;
		tot++;
		int x=i;
		vector<int> ch;
		while (!col[x]) col[x]=tot,x=per[x],ch.pb(x);
		int k=ch.size();
		for (int j=0;j<k;j++)
		{
			double arg1=2.0*pi*j/k;
			double arg2=(pi-2.0*pi*j)/k;
			m1[ch[j]]=(com){cos(arg1),sin(arg1)};
			m2[ch[j]]=(com){cos(arg2),sin(arg2)};
		}
	}
	scanf("%s",s);
	n=strlen(s);
	scanf("%s",t);
	m=strlen(t);
}

void test1()
{
	vector<int> str;
	for (int i=0;i<n;i++) str.pb(col[s[i]-'a']);
	str.pb(0);
	for (int i=0;i<m;i++) str.pb(col[t[i]-'a']);
	vector<int> ls(n+m+1,0);
	for (int i=1;i<=n+m;i++)
	{
		int j=ls[i-1];
		while (j&&str[j]!=str[i]) j=ls[j-1];
		if (str[j]==str[i]) j++;
		ls[i]=j;
	}
	for (int i=n-1;i<m;i++)
		if (ls[i+n+1]==n) ans[i]=1;
}

void test2()
{
	pre();
	reverse(s,s+n);
	for (int i=0;i<n;i++) A[i]=m1[s[i]-'a'];
	for (int i=0;i<m;i++) B[i]=m2[t[i]-'a'];
	double target=0;
	for (int i=0;i<n;i++) target+=(m1[s[i]-'a']*m2[s[i]-'a']).x;
	FFT(A,1);FFT(B,1);
	for (int i=0;i<L;i++) A[i]=A[i]*B[i];
	FFT(A,-1);
	for (int i=n-1;i<m;i++)
		if (fabs(A[i].x-target)>0.01) ans[i]=0;
}

int main()
{
	init();
	test1();
	test2();
	for (int i=n-1;i<m;i++) printf("%d",ans[i]);
	return 0;
}