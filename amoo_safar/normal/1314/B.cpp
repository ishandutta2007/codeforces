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
const int N = 2e5 + 10;
const ll Inf = N;
const ll Log = 30;

struct DP {
	int dp[4];
	DP (){
		fill(dp, dp + 4, -Inf);
	}
};
int Get(int w, int l){
	return w + w + l;
}

int n, k, mk[N];
vector<int> v;

DP Solve(int L, int R){
	DP res;
	if(L + 2 == R){
		int fl = (mk[L] | mk[L + 1]);
		res.dp[Get(mk[L], mk[L + 1])] = fl;
		res.dp[Get(mk[L + 1], mk[L])] = fl;
		return res;
	}
	int mid = (L + R) >> 1;
	DP A = Solve(L, mid);
	DP B = Solve(mid, R);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			v = {i >> 1, j >> 1, i & 1,j & 1};
			int fl = A.dp[i] + B.dp[j] + (v[0] | v[1]) + (v[2] | v[3]);
			res.dp[Get(v[0], v[2])] = max(res.dp[Get(v[0], v[2])], fl + (v[1] | v[2]));
			res.dp[Get(v[0], v[1])] = max(res.dp[Get(v[0], v[1])], fl + (v[1] | v[2]));
			
			res.dp[Get(v[0], v[3])] = max(res.dp[Get(v[0], v[3])], fl + (v[1] | v[3]));
			res.dp[Get(v[0], v[1])] = max(res.dp[Get(v[0], v[1])], fl + (v[1] | v[3]));
			swap(v[0], v[1]);
			res.dp[Get(v[0], v[2])] = max(res.dp[Get(v[0], v[2])], fl + (v[1] | v[2]));
			res.dp[Get(v[0], v[1])] = max(res.dp[Get(v[0], v[1])], fl + (v[1] | v[2]));
			
			res.dp[Get(v[0], v[3])] = max(res.dp[Get(v[0], v[3])], fl + (v[1] | v[3]));
			res.dp[Get(v[0], v[1])] = max(res.dp[Get(v[0], v[1])], fl + (v[1] | v[3]));
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int v;
	for(int i = 0; i < k; i++){
		cin >> v;
		v --;
		mk[v] = 1;
	}
	DP A = Solve(0, 1 << n);
	int ans = max(A.dp[0], 1 + max({A.dp[1], A.dp[2], A.dp[3]}));
	cout << ans << '\n';
	return 0;
}