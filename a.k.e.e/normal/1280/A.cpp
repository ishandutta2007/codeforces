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
const int MAXN=1000005,MOD=1000000007;

int n,m;
char s[MAXN];
void solve()
{
	readint(n);
	scanf("%s",s+1);
	m=strlen(s+1);
	int res=m;
	for(int i=1;i<=n;++i)
	{
		int x=s[i]-'0'-1;
		if(m<n)
		{
			for(int j=m+1;j<=n && j<=m+(m-i)*x;++j)
				s[j]=s[j-(m-i)];
			m=min(n,m+(m-i)*x);
		}
		res=(res+1ll*(res-i+MOD)*x)%MOD;
//cerr<<x;
	}
//cerr<<endl;
	printf("%d\n",res);
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