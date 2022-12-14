#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <fstream>
#include <stack>

#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 1e3 + 100;
long double dp[maxn];
int x[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	dp[1] = r;
	for (int i = 2; i <= n; i++){
		dp[i] = r;
		for (int j = i - 1; j >= 1; j--){
			int q = abs(x[i] - x[j]);
			int p = 2 * r;
			long double l = (p * p) - (q * q);
			l = sqrt (l);
			dp[i] = max(dp[i], l + dp[j]);
		}
	}
	for (int i = 1; i <= n; i++){
		cout << fixed << setprecision(6) << dp[i] << " ";
	}
}