//#pragma comment(linker, "/STACK:1000000000")
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

const int maxn = (int)1e5 + 10;
int v[maxn];
int lnk[maxn];
int dp[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		
		map<int, int> pos;
		pos[0] = -1;
		int s = 0;
		
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			v[i] = x;
			int to = s ^ x;
			auto it = pos.find(to);
			if (it != pos.end()) {
				lnk[i] = it->second;
			} else {
				lnk[i] = i;
			}
			s = to;
			pos[s] = i;
		}
		
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) {
				dp[i] = dp[i - 1];
				continue;
			}
			
			if (lnk[i] == i) {
				dp[i] = dp[i - 1] + 1;
				continue;
			}
			
			int w = lnk[i];
			
			if (w == -1) {
				dp[i] = min(dp[i - 1] + 1, i);
			} else {
				dp[i] = min(dp[i - 1] + 1, i - w - 1 + dp[w]);
			}
		}
		
		printf("%d\n", dp[n - 1]);
		
	}
}