#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
	return x * x;
}

template<typename T>
void chmin(T &x, T y) {
	x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
	x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
	s << "(" << x.fst << ", " << x.snd << ")";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
	s << "[";
	bool was = false;
	for (auto it : x) {
		if (was) {
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "]";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
	s << "{";
	bool was = false;
	for (auto it : x) {
		if (was) {
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "}";
	return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
	for (int i = 0; i < sz; i++) {
		s << x[i];
	}
	return s;
}


//-----------------------------------------------------------------------------

const int maxn = 505;

char dp[maxn][maxn][maxn];

int main() {

#ifdef LOCAL
	freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < maxn; j++) {
            for (int h = 0; h < maxn; h++) {
                dp[i + 1][j][h] = dp[i][j][h];
            }
        }

        for (int j = 0; j + x < maxn; j++) {
            for (int h = 0; h < maxn; h++) {
                dp[i + 1][j + x][h] |= dp[i][j][h];
                if (h + x < maxn) {
                    dp[i + 1][j + x][h + x] |= dp[i][j][h];
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < maxn; i++) {
        if (dp[n][k][i]) {
            ans.pb(i);
        }
    }

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;


	return 0;
}