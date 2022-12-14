#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7, maxn = 5e3 + 50;
string s[maxn];
int dp[30], cnt[30], a[30][30][maxn];

int main(){
    ios_base::sync_with_stdio(false);
	string t;
	cin >> t;
	s[0] = t;
	int n = s[0].size();
	for (int i = 1; i <= n; i++){
		s[i] = s[i - 1].substr(1, n);
		s[i] += s[i - 1][0];
	}
	for (int i = 1; i <= n; i++){
		cnt[s[i][0] - 'a'] ++;
		for (int j = 1; j < n; j++){
			int c = s[i][0] - 'a', ch = s[i][j] - 'a';
			a[c][ch][j] ++;
		}
	}
	for (int i = 0; i < 26; i++){
		for (int j = 1; j < n; j++){
			int tmp = 0;
			for (int k = 0; k < 26; k++){
				tmp += (a[i][k][j] == 1);
			}
			dp[i] = max (dp[i], tmp);
		}
	}
	long double ans = 0;
	for (int i = 0; i < 26; i++){
		if (cnt[i] == 0)
			continue;
		ans +=  1.0 * dp[i] / n;
	}	
	cout << fixed << setprecision(6) << ans << endl;
}