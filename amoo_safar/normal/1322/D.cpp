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
const int N = 4e3 + 10;
const int M = 8e3 + 100;
const ll Inf = 2242545357980376863LL;
const ll Log = 25;

ll dp[N][M];
ll cnt[N], ps[N];
ll l[N], s[N], C[N];



ll rev(pll st){
	if(st.S > cnt[st.F]) return -1;
	return ps[st.F] + st.S;
}
pll wh[M];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> l[i];
		cnt[l[i]] ++;
	}
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n + m; i++) cin >> C[i];

	for(int i = 1; i < N; i++) cnt[i] += (cnt[i - 1] / 2);
	ps[1] = 0;
	for(int i = 2; i < N; i++) ps[i] = ps[i - 1] + (cnt[i - 1] + 1);
	for(int i = 1; i < N; i++){
		for(int j = 0; j <= cnt[i]; j++){
			wh[ps[i] + j] = {i, j}; 
		}
	}
	ll Mx = ps[N - 1] + 1;
	for(int i = 0; i < N; i++) fill(dp[i], dp[i] + M, -Inf);

	for(int j = 0; j < Mx; j++){
		if(wh[j].S == 0) dp[n][j] = 0;
	}
	int j, k, nx;
	for(int i = n; i >= 0; i--){
		for(int S = 0; S < Mx; S++){
			j = wh[S].F;
			k = wh[S].S;
			nx = rev({j + 1, k / 2});
			if(nx != -1 && nx < Mx) dp[i][nx] = max(dp[i][nx], dp[i][S] + C[j + 1] * (k / 2));
			if(i == 0) continue;
			dp[i - 1][S] = max(dp[i - 1][S], dp[i][S]);
			if(l[i - 1] == j){
				nx = rev({j, k + 1});
				if(nx != -1 && nx < Mx) dp[i - 1][nx] = max(dp[i - 1][nx], dp[i][S] - s[i - 1] + C[j]);
			}
		}
	}
	cout << dp[0][rev({N - 1, 0})] << '\n';
	return 0;
}
/*
2
10000000 9999999
*/