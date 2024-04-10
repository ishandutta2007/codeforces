#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define x first
#define y second
#define pb push_back
#define br break
#define ct continue
#define rt return
#define vt vector
#define gt greater
#define prq priority_queue
#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define dbg(W) cerr<<(#W)<<"::"<<(W)<<'\n'
#define dbga(V) cerr<<(#V)<<"::";for(auto&i:V)cout<<i<<' ';cerr<<'\n'
#define RTE cerr<<__LINE__<<'\n',exit(0)
using namespace std;
using namespace __gnu_pbds;
using pii=pair <int,int>;
using tii=pair <pii,int>;
using rii=pair <int,pii>;
using qii=pair <pii,pii>;
const int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,-1,1};
template <typename T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <typename T> using rset=tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1000000007ll;
//const int mod=998244353ll;
mt19937 mt(time(nullptr));
void solve(){
	int n,m;
	cin>>n>>m;
	int p[n+1];
	for (int i=1; i<=n; i++) cin>>p[i];
	int ps[n+1]={};
	for (int i=1; i<=n; i++) ps[i]=ps[i-1]+p[i];
	int pos[m+1];
	for (int i=1; i<=m; i++) cin>>pos[i];
	map <int,int> mp;
	oset <int> l;
	rset <int> r;
	for (int i=1; i<=m; i++){
		l.insert(pos[i]);
		r.insert(pos[i]);
	}
	for (int i=1; i<=n; i++){
		//biggest <=
		int left=-1e18,right=1e18;
		int idx=l.order_of_key(100*i-99);
		if (idx) left=*l.find_by_order(idx-1);
		//smallest >=
		idx=r.order_of_key(100*i-101);
		if (idx) right=*r.find_by_order(idx-1);
		int dis=min(100*(i-1)-left,right-100*(i-1));
	//	cout<<i<<' '<<left<<' '<<right<<' '<<dis<<'\n';
		if (dis){
			mp[1000*(i-1)-10*dis+1]+=p[i];
	//		cout<<"added "<<1000*(i-1)-10*dis+1<<" to "<<p[i]<<'\n';
			mp[1000*(i-1)+10*dis-1]-=p[i];
	//		cout<<"added "<<1000*(i-1)+10*dis-1<<" to "<<-p[i]<<'\n';
		}
	}
	int ans=0,cur=0;
	for (auto i:mp){
		cur+=i.y;
		ans=max(ans,cur);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
//	cin>>t;
	while (t--) solve();
}