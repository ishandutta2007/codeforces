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
const int MAXN=5005;

int n,m,res[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int cnt=0;
	readint(n),readint(m);
	for(int i=1;i<=n;++i)
	{
		cnt+=(i-1)/2;
		res[i]=i;
		if(cnt>=m)
		{
			int cur=1000000000;
			res[i]+=2*(cnt-m);
			for(int j=n;j>i;--j)
			{
				cur-=res[i]+1;
				res[j]=cur;
			}
			for(int j=1;j<=n;++j)printf("%d ",res[j]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}