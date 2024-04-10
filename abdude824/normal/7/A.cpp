#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;

char w[9][9];

int main() {
	for (int i = 0; i < 8; i++) gets (w[i]);
	int ans = 17;
	for (int ma = 0; ma < 256; ma++)
		for (int mb = 0; mb < 256; mb++) {
			int ok = 1;
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					if (w[i][j] == 'W' && (((ma >> i) & 1) == 1 || ((mb >> j) & 1) == 1) || w[i][j] == 'B' && (((ma >> i) & 1) == 0 && ((mb >> j) & 1) == 0))
						ok = 0;
			if (ok) {	
				int cur = 0;
				for (int i = 0; i < 8; i++) cur += ((ma >> i) & 1) + ((mb >> i) & 1);
				if (cur < ans) ans = cur;
			}
		}
	printf ("%d\n", ans);
	return 0;
}