/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (1 << 6) + 10;
ld z[maxn][maxn];
ld pr[maxn][6];

const ld eps = 1e-12;

int n;

int rnd(int x, int y) {
	if (x == y) {
		return -1;
	}

	int ans = -1;

	while (x != y) {
		ans++;
		x >>= 1;
		y >>= 1;
	}

	return ans;
}

ld dp[maxn][7][maxn];
bool used[maxn][7][maxn];

ld go(int l, int d, int c) {
    if (used[l][d][c]) {
        return dp[l][d][c];
    }
    
    used[l][d][c] = true;
    
    if (c == maxn - 1) {
        ld ans = 0;
        
        for (int i = l; i < l + (1 << d); i++) {
            ans = max(ans, go(l, d, i));
        }
        
        return dp[l][d][c] = ans;
    }
    
    if (d == 0) {
        return dp[l][d][c] = 0;
    }
    
    ld ans = pr[c][d - 1] * (1 << (d - 1));
    
    if (c < l + (1 << (d - 1))) {
        ans += go(l, d - 1, c);
        ans += go(l + (1 << (d - 1)), d - 1, maxn - 1);
    } else {
        ans += go(l, d - 1, maxn - 1);
        ans += go(l + (1 << (d - 1)), d - 1, c);
    }
    
    return dp[l][d][c] = ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			cin >> z[i][j];
			z[i][j] /= 100;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			for (int t = 0; t < (1 << n); t++) {
				if (rnd(j, t) == i) {
					pr[j][i] += (i == 0 ? 1.0 : pr[t][i - 1]) * z[j][t];
				}
			}

			if (i != 0) {
				pr[j][i] *= pr[j][i - 1];
			}
		}
	}

	printf("%.100lf\n", (double)go(0, n, maxn - 1));

	return 0;
}