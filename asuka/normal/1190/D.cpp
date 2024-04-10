#include<bits/stdc++.h>
#define int long long
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
#define all(x) x.begin(),x.end()
#define VI vector<int>
using namespace std;
struct node{
	int x,y;
}p[N];
int n;
set<int> S;
VI vx,vy;
bool cmp(node a,node b){
	if(a.y != b.y) return a.y > b.y;
	else return a.x < b.x;
}
namespace BIT{
	int d[N*3];
	void add(int p){
		p++;
		//printf("p: %d\n", p);
		if(S.find(p) != S.end()) return;
		S.insert(p);
		for(;p <= N*2;p += lowbit(p)) d[p]++;
	}
	int query(int p){
		int res = 0;
		p++;
		for(;p;p -= lowbit(p)) res += d[p];
		return res;
	}
	int query(int l,int r){ //printf("l,r: %d %d\n",l,r); 
	 if(l>r) return 0;
	 return query(r) - query(l-1); }

}
using namespace BIT;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld%lld",&p[i].x,&p[i].y),vx.pb(p[i].x),vy.pb(p[i].y);
	sort(all(vx)); vx.erase(unique(all(vx)),vx.end());
	sort(all(vy)); vy.erase(unique(all(vy)),vy.end());
	rep(i,1,n) p[i].x = lower_bound(all(vx),p[i].x)-vx.begin()+1
			  ,p[i].y = lower_bound(all(vy),p[i].y)-vy.begin()+1;
    //puts("zpsakking");
	// rep(i,1,n) printf("%d %d\n",p[i].x,p[i].y);
	sort(p+1,p+n+1,cmp);rep(i,1,(int)vy.size()) vy[i-1] = i;
	reverse(all(vy));
	int cur = 0,ans = 0;
	for(auto Y:vy){
		int las = 0;
		while(cur+1 <= n && p[cur+1].y >= Y){
			cur++;  add(p[cur].x);
			//rep(i,1,3) printf("%d ",query(i)); puts("");
			int sum = query(las+1,p[cur].x-1);// puts("yes");
			//printf("sum: %d\n",sum);
			las = p[cur].x;
			ans -= sum*(sum+1)/2;
		}
		int ss = query(las+1,N*2);
		ans -= ss*(ss+1)/2;
		//printf("ss: %d\n",ss);
		int sum = query(N*2);
		ans += sum*(sum+1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}