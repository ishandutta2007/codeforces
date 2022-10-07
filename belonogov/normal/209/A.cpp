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

const int maxn = 1e6 + 2;
const int inf = 1e9;
const int mod = 1e9 + 7;

int dp[maxn][2];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int p1, p2, n;
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i < n; i++){
		p1 = i % 2;
		p2 = (i + 1) % 2;
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][1];
		dp[i][p1] = (dp[i][p1] + dp[i - 1][p2] + 1) % mod;		
	}
	cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;
 
 
    return 0;
}