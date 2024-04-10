#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
void readint(int &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
inline void chkmin(int &x,int y){x>y?x=y:0;}
inline void chkmax(int &x,int y){x<y?x=y:0;}
const int MAXN=50005,MOD=998244353;

int n;
struct Point
{
	int x,y,z,id;
	inline bool operator <(const Point &b)const
	{
		if(x==b.x)return y==b.y?z<b.z:y<b.y;
		return x<b.x;
	}
}a[MAXN],b[MAXN],c[MAXN];
bool vis[MAXN];
void solve(int L,int R)
{
	if(L>R)return;
	for(int i=L;i+1<=R;i+=2)
	{
		vis[a[i].id]=vis[a[i+1].id]=1;
		printf("%d %d\n",a[i].id,a[i+1].id);
	}
}
void work(int l,int r)
{
	for(int L=l,R;L<=r;L=R+1)
	{
		for(R=L;R<r && a[R+1].y==a[L].y;++R);
		solve(L,R);
	}
	int cnt=0;
	enum(i,l,r)
		if(!vis[a[i].id])b[++cnt]=a[i];
	for(int i=1;i+1<=cnt;i+=2)
	{
		vis[b[i].id]=vis[b[i+1].id]=1;
		printf("%d %d\n",b[i].id,b[i+1].id);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	enum(i,1,n){readint(a[i].x),readint(a[i].y),readint(a[i].z);a[i].id=i;}
	sort(a+1,a+n+1);
	for(int l=1,r;l<=n;l=r+1)
	{
		for(r=l;r<n && a[r+1].x==a[l].x;++r);
		work(l,r);
	}
	int cnt=0;
	enum(i,1,n)
		if(!vis[a[i].id])c[++cnt]=a[i];
	for(int i=1;i<=cnt;i+=2)
		printf("%d %d\n",c[i].id,c[i+1].id);
	return 0;
}