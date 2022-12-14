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
const int mod = 1e9 + 7, maxn = 1e6 + 100;
int dp[maxn][10];
set <string> suff;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	s += "000000";
	dp[n][2] = 1;
	dp[n][3] = 1;
	for (int i = n - 2; i > 4; i--){
		dp[i][2] = (dp[i + 2][2] * (s.substr(i, 2) != s.substr(i + 2, 2))) | (dp[i + 2][3]);
		dp[i][3] = (dp[i + 3][2]) | (dp[i + 3][3] * (s.substr(i, 3) != s.substr(i + 3, 3)));
		for (int j = 2; j <= 3; j++)
			if (dp[i][j])
				suff.insert(s.substr(i, j));
	}
	cout << suff.size() << '\n';
	for (auto w : suff)
		cout << w << '\n';
}