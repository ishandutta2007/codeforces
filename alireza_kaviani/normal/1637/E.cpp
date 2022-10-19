#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , m , A[MAXN];
map<int , int> cnt;
vector<pii> bad;
vector<int> vec[MAXN];

int check(int v , int u){
	if(v > u)	swap(v , u);
	int ind = lower_bound(all(bad) , pii(v , u)) - bad.begin();
	if(ind < SZ(bad) && bad[ind] == pii(v , u)){
		return 0;
	}
	return 1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cnt.clear(); bad.clear();
		cin >> n >> m;
		for(int i = 0 ; i < n + 5 ; i++){
			vec[i].clear();
		}
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			cnt[A[i]]++;
		}
		for(int i = 0 ; i < m ; i++){
			int v , u;
			cin >> v >> u;
			bad.push_back({v , u});
		}
		for(auto &i : cnt){
			bad.push_back({i.X, i.X});
//			cout << i.X << sep << i.X << endl;
			vec[i.Y].push_back(i.X);
		}
		sort(all(bad));
		vector<int> all;
		for(int i = 1 ; i <= n ; i++){
			sort(all(vec[i]), greater<int>());
			if(SZ(vec[i])){
				all.push_back(i);
			}
		}
		ll ans = 0;
		for(int x : all){
			for(int y : all){
				ll sum = x + y , mx = 0;
				for(int i : vec[x]){
					if(check(i , vec[y][0])){
						mx = max(mx , (ll)i + vec[y][0]);
						break;
					}
					for(int j : vec[y]){
						if(check(i , j)){
							mx = max(mx , (ll)i + j);
							break;
						}
					}
				}
//				cout << x << sep << y << sep << sum << sep << mx << endl;
				ans = max(ans , sum * mx);
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/