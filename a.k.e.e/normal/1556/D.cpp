#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MAXN=10005;

int n,k;
ll a[MAXN];
ll qor(int x,int y){printf("or %d %d\n",x,y);fflush(stdout);ll z;readint(z);return z;}
ll qand(int x,int y){printf("and %d %d\n",x,y);fflush(stdout);ll z;readint(z);return z;}

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(k);
	ll x=qor(1,2)+qand(1,2),y=qor(1,3)+qand(1,3),z=qor(2,3)+qand(2,3);
	a[1]=(x+y-z)/2,a[2]=(x+z-y)/2,a[3]=(y+z-x)/2;
	for(int i=4;i<=n;++i)a[i]=qor(1,i)+qand(1,i)-a[1];
	sort(a+1,a+n+1);
	printf("finish %lld\n",a[k]);
	return 0;
}