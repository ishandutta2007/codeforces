#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
using namespace std;
int lst[N],pre[N],n,a[N],vis[N];
namespace BIT{
	int c[N];
	void init(){rep(i,1,n) c[i] = n+1;}
	void upd(int x,int v){for(;x<=n;x+=lowbit(x)) c[x]=min(c[x],v);}
	int query(int x){
		int res = inf;
		for(;x;x-=lowbit(x)) res = min(res,c[x]);
		return res;
	}
}
using namespace BIT;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	init();
	rep(i,1,n+1) pre[i] = n+2;
	rep(i,1,n) scanf("%d",&a[i]),pre[i] = lst[a[i]],lst[a[i]] = i;
	rep(i,1,n) upd(i,lst[i]);
	rep(i,1,n+1){
		if(lst[i] != n && query(i-1) > lst[i]) vis[i] = 1;
	}
	int ans = 1;
	per(i,1,n){
		upd(a[i],pre[i]);
		if(pre[i] != i-1 && query(a[i]-1) > pre[i]) vis[a[i]] = 1;
	}
	while(vis[ans]) ans++;
	printf("%d\n",ans);
	return 0;
}