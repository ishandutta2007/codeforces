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


struct qe {
	int type, x, y, z;
	qe(int type, int x, int y = 0, int z = 0) :type(type), x(x), y(y), z(z) {}
};

int main() {

#ifdef LOCAL
    freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);
#endif

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	vector<vector<int>> a(n, vector<int>(m, 0));

	vector<qe> q;
	for (int i = 0; i < k; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			x--;
			q.emplace_back(1, x);
		} else if (type == 2) {
			int x;
			cin >> x;
			x--;
			q.emplace_back(2, x);
		} else {
			int x, y, z;
			cin >> x >> y >> z;
			x--, y--;
			q.emplace_back(3, x, y, z);
		}
	}

	vector<int> tmp(n);

	reverse(q.begin(), q.end());

	for (auto p : q) {
		if (p.type == 3) {
			a[p.x][p.y] = p.z;
		} else if (p.type == 2) {
			for (int j = 0; j < n; j++) {
				tmp[j] = a[j][p.x];
			}
			rotate(tmp.begin(), tmp.end() - 1, tmp.end());
			for (int j = 0; j < n; j++) {
				a[j][p.x] = tmp[j];
			}
		} else {
			rotate(a[p.x].begin(), a[p.x].end() - 1, a[p.x].end());
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j) {
				cout << " ";
			}
			cout << a[i][j];
		}
		cout << endl;
	}

    return 0;
}