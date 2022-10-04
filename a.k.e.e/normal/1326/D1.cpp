#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1000005;

int n,p[MAXN*2];
char s[MAXN],a[MAXN*2];
void manacher(int n,char *s)
{
	int pos=1,mr=1;
	p[1]=1;
	for(int i=2;i<=n;i++)
	{
		p[i]=1;
		if(i<=mr)p[i]=min(p[pos*2-i],mr-i+1);
		for(int j=p[i];j<=n;j++)
		{
			if(i-j<=0 || i+j>n || s[i-j]!=s[i+j])break;
			p[i]=j+1;
		}
		if(i+p[i]-1>mr)
		{
			mr=i+p[i]-1;
			pos=i;
		}
	}
}
void solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=2*n;++i)a[i]=(i&1)?'$':s[i>>1];
	a[1]=a[2*n+1]='#';
	manacher(2*n+1,a);
	int len=2*n+1;
	for(int i=1;i<=2*n+1;++i)
		if(a[i]!=a[2*n-i+2]){len=i-1;break;}
	if(len==2*n+1)
	{
		printf("%s\n",s+1);
		for(int i=1;i<=2*n+1;++i)a[i]=0,p[i]=0;
		for(int i=1;i<=n;++i)s[i]=0;
		return;
	}
	int l=len,r=2*n-len+2;
	for(int i=len+1;i<=2*n-len+1;++i)
	{
		if(i<=n+1 && i-p[i]<=len)chkmax(l,i+(i-len)-1);
		if(i>=n+1 && i+p[i]>=2*n-len+2)chkmin(r,i-(2*n-len+2-i)+1);
	}
	if(l>2*n-r+2)r=2*n-len+2;
	else l=len;
	for(int i=1;i<=2*n+1;++i)
		if((i<=l || i>=r) && islower(a[i]))putchar(a[i]);
	putchar('\n');
	for(int i=1;i<=2*n+1;++i)a[i]=0,p[i]=0;
	for(int i=1;i<=n;++i)s[i]=0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}