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

const ll MAXN = 3e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , q , cnt[MAXN] , ans[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	for(int i = 1 ; i < MAXN ; i++){
		for(int j = 1 ; i * j < MAXN ; j++){
			if(i == j){
				ans[i * j] += cnt[i] * (cnt[i] - 1);
				continue;
			}
			ans[i * j] += cnt[i] * cnt[j];
		}
	}
	partial_sum(ans , ans + MAXN , ans);
	cin >> q;
	while(q--){
		int x;
		cin >> x; x--;
		cout << n * (n - 1) - ans[x] << endl;
	}

    return 0;
}
/*

*/