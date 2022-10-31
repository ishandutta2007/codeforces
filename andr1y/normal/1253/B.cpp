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
#define N 100005
#define INF 101111111111111
using namespace std;
ll a[N], p[N];
vector<ll> zs;
unsigned short cnt[N*10];
unsigned int last_ment[N*10];
ll binsearch(ll start, ll end){
	ll l = 0, r = zs.size()-1;
	while(r-l>1){
		ll m = (l+r)>>1;
		if(zs[m] < start) l = m;
		else if(zs[m] > end) r = m;
		else l = m;
	}
	for(ll i = r;i>=l;i--) if(zs[i] >= start && zs[i] <= end) return i;
	return -1;
}
int main(){
	FAST;
	ll n;
	cin >> n;
	bool flag = true;
	for(ll ob, b, i =0;i<n;i++){
		cin >> a[i];
		p[i] = a[i];
		if(i > 0) p[i] += p[i-1];
		if(p[i] == 0) zs.pb(i);
	}
	if(p[n-1] != 0) cout << -1 << endl;
	else{
		bool flag = true;
		set<ll, greater<ll>> bends;
		for(ll i = 0;i<n;i++){
			if(a[i] > 0){
				if(cnt[a[i]] == 0){
					cnt[a[i]] = 1;
				}else if(cnt[a[i]] == 1){
					flag = false;
					break;
				}else if(cnt[a[i]] == 2){
					ll bsr = binsearch((bends.size() == 0 ? 0 : *(bends.begin())), i-1);
					if(bsr == -1){
						flag = false;
						break;
					}else{
						if(zs[bsr]>=last_ment[a[i]]) {
							bends.insert(zs[bsr]);
							cnt[a[i]] = 1;
							continue;
						}
						else{
							flag = false;
							break;
						}
					}
				}
			}else{
				if(cnt[-a[i]] == 0){
					flag = false;
					break;
				}else if(cnt[-a[i]] == 1){
					cnt[-a[i]] = 2;
				}else if(cnt[-a[i]] == 2){
					flag = false;
					break;
				}
			}

			last_ment[abs(a[i])] = i;
		}
		if(flag){
			cout << bends.size()+1 << endl;
			vector<ll> bds;
			while(!bends.empty()){
				bds.pb(*(bends.begin()));
				bends.erase(bends.begin());
			}
			reverse(itr(bds));
			ll now = -1;
			for(auto i : bds){
				cout << i - now << " ";
				now = i;
			}
			cout << n-now-1 << endl;
		}else{
			cout << -1 << endl;
		}
	}
}