#include<bits/stdc++.h>
#define int long long
#define N 3055
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
int n,m,p,k;
int pre[N],nxt[N],pos[N];
vector<pii> t[N];
struct node{
	int x,y,id;
	bool operator <(const node &rhs) const{
		if(y != rhs.y) return y < rhs.y;
		else return x < rhs.x;
	}
}a[N];
int tot;
int ans,res;
void del(int x){
	int ori,aft; ori = aft = 0;
	int l = nxt[x],r = x;
	rep(_,1,k) r = nxt[r];
	rep(_,1,k+1){
		// printf("ori %lld %lld %lld\n",l,r,(a[l].y - a[pre[l]].y) * (m - a[r].y + 1));
		ori += (a[l].y - a[pre[l]].y) * (m - a[r].y + 1),r = pre[r],l = pre[l];
	}
	l = nxt[x],r = x;
	rep(_,1,k) r = nxt[r];
	aft += (a[l].y - a[pre[pre[l]]].y) * (m - a[r].y + 1);
	l = pre[pre[l]]; r = pre[r];
	rep(_,1,k-1){
		// printf("aft %lld %lld %lld\n",l,r,(a[l].y - a[pre[l]].y) * (m - a[r].y + 1));
		if(l == x || r == x) continue;
		aft += (a[l].y - a[pre[l]].y) * (m - a[r].y + 1),r = pre[r],l = pre[l];
	}
	res = res - ori + aft;
	nxt[pre[x]] = nxt[x];
	pre[nxt[x]] = pre[x];
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&p,&k);
	rep(i,1,p){
		int x,y; scanf("%lld%lld",&x,&y);
		t[x].pb(mp(y,i));
	}
	rep(L,1,n){
		// printf("L: %lld\n",L);
		tot = 0;
		a[tot] = (node){L,0};
		rep(i,L,n) for(auto Y:t[i]) tot++,a[tot] = (node){i,Y.fi,Y.se};
		rep(i,tot+1,tot+k) a[i] = (node){n,m+1,114514};
		sort(a,a+tot+k+1);
		// rep(i,0,tot+k){
		// 	printf("%lld %lld\n",a[i].x,a[i].y);
		// }
		rep(i,1,tot) pos[a[i].id] = i;
		rep(i,0,tot+k) pre[i] = i-1,nxt[i] = i+1;
		pre[0] = 0; nxt[tot+k] = tot+k;
		// printf("%lld\n",tot+k);
		res = 0;
		// int cans = 0;
		rep(i,1,tot) res += (a[i].y-a[i-1].y) * (m - a[i+k-1].y + 1);
		per(i,L,n){
			ans += res;
			// cans += res;
			
			int x = nxt[0];
			// VI tmp; tmp.pb(0);
			// printf("[%lld,%lld]\n",L,i);
			// while(a[x].y <= m) printf("%lld %lld\n",a[x].x,a[x].y),tmp.pb(a[x].y),x = nxt[x];
			// rep(_,1,k) tmp.pb(m+1);
			// int myans = 0;
			// rep(i,1,tmp.size()-1-k)  myans += (tmp[i] - tmp[i-1]) * (m - tmp[i+k-1] + 1);
			// printf("myans: %lld\n",myans);
			// printf("res: %lld\n", res);
			for(auto Y:t[i]) del(pos[Y.se]);
			// for(auto Y:t[i]) Del(pos[Y.se]);
		}
		// printf("CANS: %lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
10 10 10 4
7 9
8 1
5 7
6 8
6 4
5 8
4 3
1 3
5 1
6 9

8 1
6 4
6 8
6 9
7 9

ori 1 4 2
ori 0 3 0
ori 0 2 0
ori 0 1 0
aft 0 4 0
aft 0 3 0
aft 0 2 0

6 4
6 8
6 9
7 9
*/