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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

ll dp[2][5];
ll a[N];
int Main(){
	ll n, x;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> x;

	for(int i = 0; i < 2; i++) fill(dp[i], dp[i] + 5, -Inf);

	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		fill(dp[1], dp[1] + 5, -Inf);
		for(int ch = 0; ch < 4; ch ++){
			if(dp[0][ch] < 0) continue;
			dp[1][0] = max(dp[1][0], dp[0][ch]);
			bool val = true;
			if(ch >= 1)
				val &= (a[i] + a[i - 1] >= x + x);
			if(ch >= 2)
				val &= (a[i] + a[i - 1] + a[i - 2] >= x + x + x);
			
			if(val)
				dp[1][min(3, ch + 1)] = max(dp[1][min(3, ch + 1)], dp[0][ch] + 1);
		}
		swap(dp[0], dp[1]);
	}
	cout << *max_element(dp[0], dp[0] + 5) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}