#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int x, k, n, q;
set<int> S;
vector<int> V;
ll c[15];
ll dp[100100];
ll DD[100100];
ll DP[35][101][101];
map<int, ll> BAD;
vector<int> M;
void go(int len){
	for(int j = 0; j < 30; j++){
		if(len&(1<<j)){
			for(int k = 0; k < M.size(); k++){
				DD[k] = dp[k];
				dp[k] = (1ll<<60);
			}
			for(int k = 0; k < M.size(); k++){
				for(int i = 0; i < M.size();i++){
					dp[i] = min(dp[i], DD[k] + DP[j][k][i]);
				}
			}
		}
	}
}
void calc(int z){
	for(int i = 0; i < M.size(); i++){
		DD[i] = dp[i];
		dp[i] = (1ll<<60);
	}
	for(int i = 0; i < M.size(); i++){
		if(M[i]  % 2==0){
			int d = lower_bound(all(M), M[i]/2) - M.begin();
			dp[d] = min(dp[d], DD[i]);
			continue;
		}
		for(int j=1; j <= k; j++){
			if(M[i]&(1<<j)) continue;
			int x = M[i] | (1<<j);
			x >>= 1;
			int d = lower_bound(all(M), x) - M.begin();
			if(BAD.count(z - k + j)){
				dp[d] = min(dp[d], DD[i] + c[j] + BAD[z-k+j]);
			}else{
				dp[d] = min(dp[d], DD[i] + c[j]);
			}
		}
	}
}
void precalc(){
	for(int k = 1; k < 30; k++){
		for(int i = 0; i < M.size(); i++){
			for(int j = 0; j < M.size(); j++){
				DP[k][i][j] = (1ll<<60);
			}
		}
		for(int i = 0; i < M.size(); i++){
			for(int j = 0; j < M.size(); j++){
				for(int t = 0;t<M.size(); t++){
					DP[k][i][j] = min(DP[k-1][i][t] + DP[k-1][t][j], DP[k][i][j]);
				}
			}
		}
	}
}
void solve(){
	cin >> x >> k >> n >> q;
	for(int i = 1; i <=k; i++){
		cin >> c[i];
	}
	for(int i = 1; i <= x; i++){
		S.insert(i);
		S.insert(n - i + 1);
	}
	for(int i = 1; i <= k-x; i++){
		S.insert(n+i);
	}
	for(int i = x+1; i <= 2 * x + 2 * k; i++){
		if(i <= n) S.insert(i);
		if(n - i + 1 > 0) S.insert(n - i + 1);
	}
	for(int i = 0, p, D; i < q; i++){
		cin >> p >> D;
		BAD[p] = D;
		for(int j = 0; j <= 3 * k + 2; j++){
			if(j < p) S.insert(p-j);
			if(j + p <= n) S.insert(p+j);
		}
	}
	forit(it, S){
		V.pb(*it);
	}
	for(int i = 0; i < (1<<k); i++){
		if(__builtin_popcount(i) != x) continue;
		M.pb(i);
	}
	for(int i = 0; i < M.size(); i++){
		for(int j = 0; j < M.size(); j++){
			DP[0][i][j] = (1ll<<60);
		}
	}
	for(int i = 0; i < M.size(); i++){
		if(M[i]&1){
			for(int t = 1; t <= k; t++){
				if(M[i] & (1<<t)) continue;
				int x = M[i] | (1<<t);
				x >>= 1;
				int d = lower_bound(all(M), x) - M.begin();
				DP[0][i][d] = c[t];
			}
		}else{
			int d = lower_bound(all(M), M[i]/2) - M.begin();
			DP[0][i][d] = 0;
		}
	}
	precalc();

	int g = lower_bound(all(M), ((1<<x) - 1)<<(k-x)) - M.begin();
	for(int i = 0; i < M.size(); i++){
		dp[i] = (1ll<<60);
	}
	dp[g] = 0;


	for(int i = x; i < V.size(); i++){
		if(V[i] - V[i-1] > 1){	
			go(V[i] - V[i-1]);
		}else{
			calc(V[i]);
		}
	}
	cout << dp[0] << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}