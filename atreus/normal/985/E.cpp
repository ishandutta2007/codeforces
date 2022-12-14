#include <cstring>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)10903;
const int maxn = 5e5 + 100;
const int inf = (int)1e9;
int n, k, d, a[maxn], par[maxn];
bool dp[maxn];

int lef (int idx){
	int l = 0, r = idx;
	while (r - l > 1){
		int mid = (l + r) / 2;
		if (a[idx] - a[mid] <= d)
			r = mid;
		else
			l = mid;
	}
	return r;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		par[i] = par[i - 1];
		if (i < k)
			continue;
		int idx = lef (i);
		if (idx == 1)
			dp[i] = 1;	
		else if (idx <= i - k + 1)
			dp[i] = (par[i - k] - par[idx - 2] >= 1);
		par[i] += dp[i];
	}
	if (dp[n])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}