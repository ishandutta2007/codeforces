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
const int inf = 1e9 + 7, maxn = 1e6 + 200;
int a[maxn], dp[maxn][10];

int g(int x){
	if (a[x] != 0)
		return a[x];
	int k = 1, n = x;
	while (x > 0){
		int m = x % 10;
		if (m > 0)
			k *= m;
		x /= 10;
	}
	a[n] = g(k);
	return a[n];
}

int main(){ 
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 9; i++)
		a[i] = i;
	for (int i = 10; i <= 1e6 + 10; i++)
		a[i] = g(i);
	for (int i = 1; i <= 1e6 + 10; i++)
		for (int j = 1; j <= 9; j++)
			dp[i][j] = dp[i - 1][j] + (a[i] == j);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		int l, r, x;
		cin >> l >> r >> x;
		cout << dp[r][x] - dp[l - 1][x] << endl;
	}
}