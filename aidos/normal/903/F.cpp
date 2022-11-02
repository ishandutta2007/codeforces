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

set<int> S[1111];
map<int, int> C[1111];
vector<int> M[1111];
int cost[1111][1111];
int A[11];
int calc(int mask){
	int t = 1;
	for(int i = 0;i<4; i++){
		t *= 5;
	}
	for(int i = 0; i < t; i++){
		vector<int> cur;
		int m = i;
		for(int j = 0; j < 4; j++){
			cur.pb(m % 5);
			m/=5;
		}
		int bad = 0;
		for(int j = 0; j < 4; j++){
			if(cur[j] > j + 1) bad = 1;
		}
		if(bad) continue;
		vector<int> u(4, 0);
		for(int j = 0; j < 4; j++){
			for(int z = 1; z <= cur[j]; z++){
				u[j - z + 1] = 1;
			}
		}
		for(int j = 0; j < 4; j++){
			if(mask & (1<<j)) {
				if(!u[j]) bad = 1;
			}
		}
		if(bad) continue;
		int d = 0;
		int cc = 0;
		for(int j = 0; j < 4; j++){
			int st = j - cur[j] + 1;
			cc += A[cur[j]];
			for(int x = 0; x < cur[j]; x++){
				for(int y = 0; y < cur[j]; y++){
					d |= (1<<(x * 4 +st + y));
				}
			}

		}
		S[mask].insert(d);
		if(!C[mask].count(d)){
			C[mask][d] = cc;
		}
		else {
			C[mask][d] = min(C[mask][d], cc);
		}
	}
	M[mask] = vector<int>(S[mask].begin(), S[mask].end());
	for(int i = 0; i < M[mask].size(); i++){
		cost[mask][i] = C[mask][M[mask][i]];
	}
	return S[mask].size();
}
int dp[100100];
int d[100100];
string s[111];
int n;
void solve(){
	cin >> n;
	for(int i = 1; i <= 4; i++){
		cin >> A[i];
	}
	for(int i = 0; i < (1<<4); i++){
		//cout << calc(i) << endl;
		calc(i);
	}
	int cur = 16 * 16 * 16;
	for(int i = 0; i < 4; i++){
		cin >> s[i];
	}
	for(int i = 0; i < cur; i++){
		dp[i] = inf;
	}
	dp[0] = 0;
	for(int j = 0; j < 5; j++){
		n++;
		for(int i = 0; i < 4; i++){
			s[i] += '.';
		}
	}
	for(int i = 0; i < n; i++){
		int cur_mask = 0;
		for(int t = 0; t < 4; t++){
			if(s[t][i] != '.'){
				cur_mask |=(1<<(t+12));
			}
		}
		for(int mask = 0; mask < cur; mask++){
			d[mask] = dp[mask];
			dp[mask] = inf;
		}
		for(int mask = 0; mask < cur; mask++){
			int en = mask & 15;
			for(int j = 0; j < M[en].size(); j++){
				int dd = mask | cur_mask|M[en][j];
				dd ^= M[en][j];
				dd >>= 4;
				dp[dd] = min(dp[dd], d[mask] + cost[en][j]);
			}
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