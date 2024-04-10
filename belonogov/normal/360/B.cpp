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

const int maxn = 2000 + 2;
const long long inf = 1e9;


int n, k;
int a[maxn];
int dp[maxn];

bool solve(long long key){
	long long l, r;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	for (int i = 0; i < n; i++){
		l = a[i];
		r = a[i];
		for (int j = i + 1; j < n; j++){
			l -= key;
			r += key;
			if (l <= a[j] && a[j] <= r)
				dp[j] = max(dp[j], dp[i] + 1);
		}
			
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	return ans >= n - k;	
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	long long l, r;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	l = -1;
	r = 1e10;
	while (r - l > 1){
		if (solve((l + r) / 2))
			r = (l + r) / 2;
		else
			l = (l + r) / 2;
	}

	cout << r << endl;
	
    return 0;
}