#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = (1 << 16);
const int mod = 1e9 + 7;
int b[100], par[120][maxn + 10], tmp[120][maxn + 10], p[20], a[120], dp[120][maxn + 10];

bool isprime (int x) {
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int cmp = 0;
	for (int i = 2; i <= 57; i++)
		if (isprime(i))
			p[cmp ++] = i;

	int n;
	cin >> n;
	for (int i = n; i >= 1; i--)
		cin >> a[i];

	for (int i = 1; i <= 57; i++)
		for (int j = 0; j < cmp; j++)
			if (i % p[j] == 0)
				b[i] += (1 << j);

	memset (dp, 63, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << 16); j++) {
			for (int k = 1; k <= 57; k++) {
				int mask = j;
				bool cur = 1;
				if ((j & b[k]) == 0) {
					mask |= b[k];
					if (cur and dp[i + 1][mask] > dp[i][j] + abs (k - a[i + 1])) {
						tmp[i + 1][mask] = k;
						par[i + 1][mask] = j;
						dp[i + 1][mask] = dp[i][j] + abs (k - a[i + 1]);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << 16); i++) 
		if (dp[n][i] < dp[n][ans])
			ans = i;
	
	int idx = n;
	while (idx > 0) {
		cout << tmp[idx][ans] << " ";
		ans = par[idx][ans];
		idx --;
	}
	cout << endl;
}