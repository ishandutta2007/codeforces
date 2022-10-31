#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], B[MAXN];
ll ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i], ans += A[i] * B[i];

	ll fans = ans;
	for (int i = 1; i <= n; i++) {
		ll tans = ans;
		int L = i - 1, R = i + 1;
	       	while (L > 0 && R <= n) {
			tans -= A[L] * B[L];
			tans -= A[R] * B[R];
			tans += A[L] * B[R];
			tans += A[R] * B[L];
			fans = max(fans, tans);
			L--;
			R++;
		}	
	}

	for (int i = 1; i < n; i++) {
		int L = i, R = i + 1;
		ll tans = ans;
		while (L > 0 && R <= n) {
			tans -= A[L] * B[L];
			tans -= A[R] * B[R];
			tans += A[L] * B[R];
			tans += A[R] * B[L];
			fans = max(fans, tans);
			L--;
			R++;
		}
	}

	cout << fans << endl;
	return 0;
}