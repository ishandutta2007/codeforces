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

ll n , ans , cnt[4];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int x , y;
		cin >> x >> y;
		x /= 2; y /= 2;
		x %= 2; y %= 2;
		cnt[x * 2 + y]++;
	}
	ans = n * (n - 1) * (n - 2) / 6;
	for(int i = 0 ; i < 4 ; i++){
		for(int j = i + 1 ; j < 4 ; j++){
			for(int k = j + 1 ; k < 4 ; k++){
				ans -= cnt[i] * cnt[j] * cnt[k];
			}
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/