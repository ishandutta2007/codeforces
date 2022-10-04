#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=1005;

int n,a[MAXN],b[MAXN];
pii p[MAXN];
int m;
pii op[MAXN*MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(p[i].x),p[i].y=i;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i)a[p[i].y]=i,b[i]=p[i].y;
	for(int i=1;i<=n;++i)
		for(int j=1;j<n;++j)
			if(a[j]>a[j+1])op[++m]=mp(a[j],a[j+1]),swap(a[j],a[j+1]);
	printf("%d\n",m);
	for(int i=m;i;--i)
		printf("%d %d\n",b[op[i].x],b[op[i].y]);
	return 0;
}