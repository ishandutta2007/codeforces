#include <bits/stdc++.h>


#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int H = 2e2 + 10;
const int D = 4200 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ld dp[D][H];
ld dp2[D][H];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll h1, d1, l1, r1, p1;
	cin >> h1 >> d1 >> l1 >> r1 >> p1;
	ll h2, d2, l2, r2, p2;
	cin >> h2 >> d2 >> l2 >> r2 >> p2;

	dp[0][h2] = 1;
	ld P = ((ld)p1)/100;
	ld Fa = (1 - P) / (r1 - l1 + 1);
	for(int i = 1; i < D; i++){
		for(int k = 1; k < H; k++){
			dp[i][k] += dp[i - 1][k] * P;
			for(int j = l1; j <= r1; j++){
				dp[i][max(0, k - j)] += dp[i - 1][k] * Fa;
			}
		}
	}
	swap(dp, dp2);
	dp[0][h1] = 1;
	P = ((ld)p2)/100;
	Fa = (1 - P) / (r2 - l2 + 1);
	for(int i = 1; i < D; i++){
		for(int k = 1; k < H; k++){
			dp[i][k] += dp[i - 1][k] * P;
			for(int j = l2; j <= r2; j++){
				dp[i][max(0, k - j)] += dp[i - 1][k] * Fa;
			}
		}
	}
	ld ans = 0;
	ld A, B;
	for(int i = 1; i < D; i++){
		B = 0;
		A = dp2[i][0];
		
		ll cnt = min(D - 1ll, 1 + ((i - 1) * d1) / d2);
		if((i - 1) * d1 % d2 == 0) cnt --;
		for(int j = 1; j < H; j++){
			B += dp[cnt][j];
		}
		//if(0 < max(A, B)) cerr << fixed << setprecision(4) << A << " " << B << '\n';
		ans += A * B;
	}


	cout << fixed << setprecision(8) << ans << '\n';
	return 0;
}