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

const ll Mod = 1e9 + 9;
const int N = 16;
const ll Inf = 2242545357980376863LL;
const ll Log = 14;


ll ans[(1<<Log) + 10];

bool G[N][(1 << Log) + 10];

ll dp[(1 << Log) + 10][N];
int n;
vector<int> V[N];

void Solve(ll x, ll d){
	//debug(x);
	if(d == n){
		for(int i = 0; i < n; i++) ans[x] += dp[(1 << n) - 1][i];
		return ;
	}
	for(auto y : V[d + 1]) for(int i = 0; i < n; i++) dp[y][i] = 0;
	int y2 = 0, lb;
	for(auto y : V[d]){
		for(int i = 0; i < n; i++){
			if(y >> i & 1){
				y2 = y ^ ((1 << n) - 1);
				while(y2){
					lb = (y2) & (-y2);
					if(!G[i][lb])
						dp[y | lb][__builtin_ctz(lb)] += dp[y][i];
					y2 -= lb;
				}

			}
		}
	}
	Solve(x + x, d + 1);

	for(auto y : V[d + 1]) for(int i = 0; i < n; i++) dp[y][i] = 0;
	for(auto y : V[d]){
		for(int i = 0; i < n; i++){
			if(y >> i & 1){
				y2 = y ^ ((1 << n) - 1);
				while(y2){
					lb = (y2) & (-y2);
					if(G[i][lb])
						dp[y | lb][__builtin_ctz(lb)] += dp[y][i];
					y2 -= lb;
				}
			}
		}
	}
	Solve(x + x + 1, d + 1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	char c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c;
			G[i][1<<j] = (c == '0' ? 0 : 1);
		}
	}
	for(int i = 0; i < (1 << n); i++){
		V[__builtin_popcount(i)].pb(i);
	}
	for(int i = 0; i < n; i++) dp[(1 << i)][i] = 1;
	Solve(0, 1);
	for(int i = 0; i < 1 << (n - 1); i++) cout << ans[i] << ' ';

	return 0;
}
/*
1
abcdfdcecba

*/