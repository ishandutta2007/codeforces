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
const int MAXN=100005;

int n,a[MAXN][2],cnt;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,x,y;
	readint(n),readint(Q);
	while(Q--)
	{
		readint(y),readint(x);--y;
		for(int i=x-1;i<=x+1;++i)
			cnt-=(a[i][y^1]&&a[x][y]);
		a[x][y]^=1;
		for(int i=x-1;i<=x+1;++i)
			cnt+=(a[i][y^1]&&a[x][y]);
		printf(cnt?"No\n":"Yes\n");
	}
	return 0;
}