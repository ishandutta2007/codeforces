#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		vector<int> vec;
		for(int i = 0 ; i < n ; i++){
			int x;
			cin >> x;
			if(x & 1){
				vec.push_back(i);
			}
		}
		ll ans = INF;
		for(int i = 0 ; i < 2 ; i++){
			vector<int> sec;
			for(int j = i ; j < n ; j += 2){
				sec.push_back(j);
			}
			if(SZ(vec) != SZ(sec)){
				continue;
			}
			ll cur = 0;
			for(int j = 0 ; j < SZ(vec) ; j++){
				cur += abs(vec[j] - sec[j]);
			}
			ans = min(ans , cur);
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}

    return 0;
}
/*

*/