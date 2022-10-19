#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
using namespace std;
vector<pii> v;
VI pos[N],fin,pp;
priority_queue<pii,vector<pii>,less<pii> > q;
int T,n,a,ans[N],vis[N],x,y,cnt[N],A[N],tag[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&T);
 	while(T--){
 		scanf("%d%d%d",&n,&x,&y);
 		rep(i,1,n+1) vis[i] = 0,cnt[i] = 0,tag[i] = 0,pos[i].clear();
 		fin.clear(); pp.clear(); while(!q.empty()) q.pop(); v.clear();
 		rep(i,1,n) scanf("%d",&a),A[i] = a,cnt[a]++,vis[a] = 1,pos[a].pb(i);
 		rep(i,1,n+1) if(cnt[i]) q.push(mp(cnt[i],i)); 
 		int smg = 0; rep(i,1,n+1) if(!vis[i]) smg = i;
 		rep(i,1,x){
 			auto t = q.top(); q.pop();
 			ans[pos[t.se].back()] = t.se; tag[pos[t.se].back()] = 1; pos[t.se].pop_back();
 			//printf("first phase: %d\n",t.se);
 			t.fi--;
 			if(t.fi == 0) continue;
 			q.push(t);
 		}
 		while(!q.empty()){v.pb(q.top());q.pop();}
 		for(auto V:v){
 			rep(i,1,V.fi){
 			    fin.pb(V.se);
 			    pp.pb(pos[V.se].back()); pos[V.se].pop_back();
 			}
 		}
 		int len = (int)fin.size();
 		//rep(i,0,len-1) printf("val: %d pos: %d\n",fin[i],pp[i]);
 		rep(i,0,len-1) ans[pp[(i+(len/2))%len]] = fin[i],tag[pp[(i+(len/2))%len]] = 2;
 		int lft = n-y;
 		rep(i,1,n) if(tag[i] == 2 && ans[i] == A[i]) ans[i] = smg,lft--;
 		rep(i,1,n){
 			if(lft <= 0) break;
 			if(tag[i] == 2 && ans[i] != smg) ans[i] = smg,lft--;
 		}
 		int cx,cy; cx = cy = 0;
 		rep(i,1,n){
 			if(ans[i] == A[i]) cx++;
 			if(cnt[ans[i]] > 0) cy++,cnt[ans[i]]--;
 		}
 		//printf("%d %d\n",cx,cy);
 		if(cx == x && cy == y && lft == 0){
 			puts("YES");
 			rep(i,1,n) printf("%d ",ans[i]);
 			puts("");
 		}else{
 			puts("NO");
 			// rep(i,1,n) printf("%d ",ans[i]);
 			// puts("");
 		}
 	}
	return 0;
}