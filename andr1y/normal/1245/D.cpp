#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 2005
#define INF 101111111111111
using namespace std;
ll conf[N];
pll pos[N];
ll oc[N], c[N], k[N];
inline ll len(ll i, ll j){
	return (k[i]+k[j])*(abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y));
}
ll res[N];
ll n;
void solve(){
	ll minv = INF, minp = -1;
	for(ll i = 1;i<=n;i++){
		if(res[i]!=0) continue;
		if(c[i] < minv){
			minv = c[i];
			minp = i;
		}
	}
	res[minp] = minv;
	for(ll i = 1;i<=n;i++){
		if(res[i] == 0){
			if(len(i, minp) < c[i]){
				conf[i] = minp;
				c[i] = len(i, minp);
			}
		}
	}
}
int main(){
	FAST;
	cin >> n;
	for(ll i = 1;i<=n;i++) cin >> pos[i].x >> pos[i].y;
	for(ll i =1;i<=n;i++) {cin >> c[i]; oc[i] = c[i];}
	for(ll i =1;i<=n;i++) cin >> k[i];
	for(ll i = 0;i<n;i++) solve();
	vector<ll> stations;
	vector<pll> cons;
	for(ll i = 1;i<=n;i++) {if(res[i] == oc[i]) stations.pb(i); else cons.pb({i, conf[i]});}
	ll rl = 0;
	for(ll i = 1;i<=n;i++) rl += res[i];
	cout << rl << endl;
	cout << stations.size() << endl;
	for(auto i : stations) cout << i << " ";
	cout << endl << cons.size() << endl;
	for(auto i : cons) cout << i.x << " " << i.y << endl;
}