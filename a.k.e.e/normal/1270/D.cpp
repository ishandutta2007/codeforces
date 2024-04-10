#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
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
const int MAXN=505;

int n,k,a[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int x;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k+1;++i)
	{
		printf("? ");
		for(int j=1;j<=k+1;++j)if(j!=i)printf("%d ",j);
		putchar('\n');
		fflush(stdout);
		scanf("%d%d",&x,&a[i]);
	}
	int ans=0;
	sort(a+1,a+k+2);
	for(int i=k+1;i;--i)
		if(a[i]==a[k+1])++ans;
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}