// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const ll N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[N], odp[N];

ll A[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	reverse(A, A + n);
	fill(dp, dp + N, - Inf);
	if((h >= a && w >= b) || (h >= b && w >= a)) return cout << "0\n", 0;
	dp[w] = h;
	dp[h] = w;
	for(int i = 0; i < n; i++){
		ll d = A[i];
		fill(odp, odp + N, - Inf);	
		for(int j = 1; j < N; j++){
			if(dp[j] <= 0) continue;
			odp[j] = max(odp[j], min(N - 1, dp[j] * d));
			odp[min(N - 1, j * d)] = max(odp[min(N - 1, j * d)], dp[j]);
		}
		for(int j = 0; j < N; j++){
			dp[j] = max(dp[j], odp[j]);
			if(j >= a && dp[j] >= b) return cout << i + 1 << '\n', 0;
		}
	}
	cout << "-1\n";
	return 0;
}