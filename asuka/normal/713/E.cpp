#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,a[N],p[N],f[N];
bool check(int x){
	f[1] = 0;
	// < - 1
	rep(i,2,n){
		f[i] = f[i-1];
		if(f[i-1] >= p[i] - 1) f[i] = max(f[i],p[i] + x);
		if(f[i-1] >= p[i] - x - 1) f[i] = max(f[i],p[i]);
		if(i > 2 && f[i-2] >= p[i] - x - 1) f[i] = max(f[i],p[i-1] + x);
	}
	if(f[n] >= m - 1 - x) return 1;
	// 1 - >
	if(p[1] + x < p[2] - x) return 0;
	f[2] = max(p[1] + x,p[2]);
	rep(i,3,n){
		f[i] = f[i-1];
		if(f[i-1] >= p[i] - 1) f[i] = max(f[i],p[i] + x);
		if(f[i-1] >= p[i] - x - 1) f[i] = max(f[i],p[i]);
		if(i > 2 && f[i-2] >= p[i] - x - 1) f[i] = max(f[i],p[i-1] + x);
	}
	if(f[n] >= m - 1 - max(x - p[2],0)) return 1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&m,&n);
	rep(i,1,n) scanf("%d",&a[i]),a[i+n] = a[i] + m;
	sort(a+1,a+n+n+1);
	if(n == 1){
		printf("%d\n",m-1);
		return 0;
	}
	int pos = 2;
	int l = 0,r;
	rep(i,2,n+1) if(a[i] - a[i-1] > a[pos] - a[pos-1]) pos = i;
	r = a[pos] - a[pos-1] - 1;
	rep(i,1,n) p[i] = a[i+pos-1];
	int st = p[1];
	rep(i,1,n) p[i] -= st;
	int ans = 114514;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)) ans = mid,r = mid-1;
		else l = mid+1;
	}
	printf("%d\n",ans);
	return 0;
}