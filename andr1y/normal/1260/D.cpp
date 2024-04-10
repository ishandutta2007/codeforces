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
#define N 200005
#define INF 101111111111111
using namespace std;
pll traps[N];
vector<ll> traps_on_road[N];
ll voins[N], m, n, k, t;
ll gettime(ll mind){
	ll nowto = -1, start = -1;
	ll totalblocks = 0;
	for(ll i = 1;i<=n;i++){
		if(traps_on_road[i].size() > 0){
			ll to = -1;
			for(auto j : traps_on_road[i]) if(traps[j].x > mind) to = max(to, traps[j].y);
			if(to != -1){
				if(nowto == -1){
					nowto = to;
					start = i;
				}else{
					nowto = max(nowto, to);
				}
			}
		}
		if(nowto == i){
			totalblocks += nowto-start+1;
			nowto = -1, start = -1;
		}
	}
	return n+totalblocks*2+1;
}
ll bins(){
	ll l = 0, r = m-1;
	while(r-l>1){
		ll m1 = (l+r)>>1;
		if(gettime(voins[m1]) <= t) r = m1;
		else l = m1;
	}
	for(ll m1 = l;m1<=r;m1++) if(gettime(voins[m1]) <= t) return m1;
	return m;
}
int main(){
	FAST;
	cin >> m >> n >> k >> t;
	for(ll i =0;i<m;i++){
		cin >> voins[i];
	}
	sort(voins, voins+m);
	for(ll i = 0;i<k;i++){
		ll at, cl, dead;
		cin >> at >> cl >> dead;
		traps[i] = {dead, cl};
		traps_on_road[at].pb(i);
	}
	cout << m-bins() << endl;
}