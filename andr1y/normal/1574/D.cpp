//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;
vector<ll> a[10];
ll ban[N][10];
const ll P = 200003;
const ll M = 1014881489;
map<pull, bool> bh, was;
typedef pair<ll, vector<ll>> pq_o;
struct cust_g{
	bool operator()(const pq_o &a, const pq_o &b) const{
		return a.x > b.x;
	}
};
priority_queue<pq_o,vector<pq_o>,cust_g> pq;
pull p[12];
ll n;
pull mkh(vector<ll> &a){
	pull x = {0, 0};
	for(ll i = 0;i<n;i++){
		x.x+=p[i].x*(a[i]+1);
		x.y+=p[i].y*(a[i]+1);
		x.y%=M;
	}
	return x;
}


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	p[0]={1, 1};
	for(ll i = 1;i<12;i++) p[i]={p[i-1].x*P, p[i-1].y*P%M};
	ll m;
	cin >> n;
	for(ll i = 0;i<n;i++){
		ll sz;cin >> sz;
		a[i].resize(sz);
		for(ll j = sz-1;j>=0;j--){
			cin >> a[i][j];
			if(j!=sz-1) a[i][j+1] = a[i][j]-a[i][j+1];
			a[i][0]=0;
		}
	}
	cin >> m;
	for(ll i = 0;i<m;i++){
		pull x = {0, 0};
		for(ll j =0;j<n;j++){
			cin >> ban[i][j];
			ban[i][j] = a[j].size()-ban[i][j];
			x.x+=p[j].x*(ban[i][j]+1);
			x.y+=p[j].y*(ban[i][j]+1);
			x.y%=M;
		}
		bh[x]=1;
	}
	vector<ll> __(n, 0);
	pq.push({0, __});
	was[mkh(__)]=1;
	while(!pq.empty()){
		pq_o now = pq.top();pq.pop();
		pull h = mkh(now.y);
		if(!bh.count(h)){
			ll j =0;
			for(auto i : now.y){
				cout<<a[j++].size()-i<<' ';
			}
			return 0;
		}
		for(ll go=0;go<n;go++){
			if(now.y[go]+1<a[go].size()){
				pull nh = h;
				nh.x += p[go].x;
				nh.y += p[go].y;
				if(nh.y>=M) nh.y-=M;
				if(!was.count(nh)){
					was[nh]=1;
					now.y[go]++;
					pq.push({now.x + a[go][now.y[go]], now.y});
					now.y[go]--;
				}
			}
		}
	}
	assert(0);
}