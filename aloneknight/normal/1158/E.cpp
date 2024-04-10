#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef bitset<N> B;
int n,k,dep[N],fa[N];
B s[2],t[4],a,b;vector<B>S;
inline B qry(B x,int y)
{
	y=min(y,n-1);char c[N];putchar('?');
	for(int i=1;i<=n;i++)printf(" %d",x[i]?y:0);
	puts("");fflush(stdout);scanf("%s",c+1);
	for(int i=1;i<=n;i++)if(c[i]=='1')x[i]=1;return x;
}
int main()
{
	scanf("%d",&n);while((1<<k)<=n)k++;s[0][1]=1;
	for(int i=1;i<=n;i++)a[i]=1;S.push_back(a);
	for(int i=k-1;~i;i--)
	{
		int len=1<<i;
		for(int j=0;j<4;j++)t[j]=qry(s[j&1],len-(j>>1));
		s[0]|=s[1];s[1].reset();vector<B>nS;
		for(int j=0;j<S.size();j++)
		{
			a=t[j&1]&S[j];b=t[(j&1)+2]&S[j];s[1]|=a^b;
			nS.push_back(b);nS.push_back(S[j]^b);
		}
		S=nS;
	}
	for(int i=0;i<S.size();i++)for(int j=1;j<=n;j++)if(S[i][j])dep[j]=i;
	for(int i=0;i<3;i++)for(int j=0;j<k;j++)
	{
		a.reset();for(int x=1;x<=n;x++)a[x]=(dep[x]%3==i&&(x>>j&1));
		a=qry(a,1);for(int x=1;x<=n;x++)fa[x]|=((dep[x]+2)%3==i&&a[x])<<j;
	}
	puts("!");
	for(int i=2;i<=n;i++)printf("%d %d\n",fa[i],i);
	return 0;
}