#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

int n;
pair <int, int> a[1000100];
int b[1000200];
int dp[1000200];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[x - 1].fir = i + 1;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[x - 1].sec = i + 1;
	}
	for (int i = 0; i < n; ++i)
		b[a[i].first - 1] = a[i].second;
	reverse(b, b + n);
	for (int i = 1; i <= n; ++i)
		dp[i] = inf;
	dp[0] = -inf;
	for (int i = 0; i < n; ++i) {
		int pos = upper_bound(dp, dp + n, b[i]) - dp;
		if ((dp[pos - 1] < b[i]) && (dp[pos] > b[i]))
			dp[pos] = b[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (dp[i] != inf)
			ans = i;
	cout << ans << endl;
	return 0;
}