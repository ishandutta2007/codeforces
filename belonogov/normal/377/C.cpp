#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = (1 << 20) + 2;
const int inf = 1e9;

int dp[maxn];
int a[1000];
char c[1000];
int T[maxn];
vector < int > M[22];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, mask, newmask;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater < int > ());
	cin >> m;
	n = m;
	for (int i = 0; i < m; i++){
		scanf(" %c%d", &c[i], &T[i]); 
		assert(c[i] == 'p' || c[i] == 'b');
	}
	
	for (int mask = 0; mask < (1 << m) - 1; mask++){
		if (T[__builtin_popcount(mask)] == 1)
			dp[mask] = -inf;
		else
			dp[mask] = inf;
		M[__builtin_popcount(mask)].pb(mask);
	}
	
// 	cerr << "dp start\n";
// 	for (int i = 0; i < (1 << n); i++)
// 		cout << dp[i] << endl;
	
	
	for (int i = m - 1; i >= 0; i--){
		for (int j = 0; j < (int)M[i].size(); j++){
			mask = M[i][j];
			for (int t = 0; t < n; t++)
				if ((mask & (1 << t)) == 0){
					newmask = mask | (1 << t);
					if (T[i] == 1)
						dp[mask] = max(dp[mask], dp[newmask] + (c[i] == 'p') * a[t]); 
					else
						dp[mask] = min(dp[mask], dp[newmask] - (c[i] == 'p') * a[t]); 
				}
		}	
	}
	cout << dp[0] << endl;
	
			
	
 
    return 0;
}