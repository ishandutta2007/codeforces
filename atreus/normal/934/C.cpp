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
const int inf = 1e9 + 7, maxn = 2000 + 100;
ll a[maxn], dp[maxn], sum[maxn][5];

int main(){ 
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--){
		sum[i][2] = sum[i + 1][2];
		if (a[i] == 2)
			sum[i][2] ++;
	}
	for (int i = 1; i <= n; i++){
		sum[i][1] = sum[i - 1][1];
		if (a[i] == 1)
			sum[i][1] ++;
	}
	ll ans = sum[n][1];
	for (int i = 1; i <= n; i++){
		if (a[i] == 1)
			continue;
		ll p = sum[i - 1][1];
		ll q = sum[i + 1][2];
		ll maxp = p, maxq = q;
		for (int j = i - 1; j >= 1; j--){
			if (a[j] == 1)
				p --;
			else
				p ++;
			maxp = max(maxp, p);
		}
		for (int j = i + 1; j <= n; j++){
			if (a[j] == 1)
				q ++;
			else
				q --;
			maxq = max(maxq, q);
		}
		ans = max(ans, maxp + maxq + 1);
	}
	cout << ans << endl;
}