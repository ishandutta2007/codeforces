#include <iostream>
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
const int inf = 1e9 + 7, maxm = 1e3 + 100, maxn = 4e6 + 500;
long double dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		long double a, b;
		cin >> a >> b;
		dp[i] = 1.0 * a / b;
	}
	sort (dp, dp + n);
	cout << fixed << setprecision(6) << 1.0 * m * dp[0] << endl;
}