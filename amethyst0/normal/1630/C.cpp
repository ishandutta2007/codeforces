#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

int n;
const int maxn = (int)2e5 + 10;
int v[maxn];
int last[maxn];
int dp[maxn];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		last[v[i]] = i;
	}
	
	vector <int> pos;
	
	for (int i = n - 1; i >= 0; i--) {
		if (last[v[i]] == i) {
			dp[i] = dp[i + 1];
			continue;
		}
		
		while (!pos.empty() && last[v[pos.back()]] <= last[v[i]]) {
			pos.pop_back();
		}
		
		int r = last[v[i]];
		
		dp[i] = dp[i + 1];
		dp[i] = max(dp[i], r - i - 1 + dp[r]);
		if (!pos.empty() && pos.back() < r) {
			int lm = 0;
			int rm = (int)pos.size() - 1;
			
			while (lm != rm) {
				int m = (lm + rm) >> 1;
				if (pos[m] < r) {
					rm = m;
				} else {
					lm = m + 1;
				}
			}
			
			int j = pos[lm];
			
			if (j < r) {
				dp[i] = max(dp[i], j - i - 1 + dp[j]);
			}
		}
		
		pos.push_back(i);
	}
	
	cout << dp[0] << '\n';
	
	return 0;
}