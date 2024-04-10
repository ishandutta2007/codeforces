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
	int x, y, z;
	qe(int x, int y = 0, int z = 0) :x(x), y(y), z(z) {}
};

struct ft {
	vector<int> a;


	void add(int v, int x) {
		while (v < a.size()) {
			a[v] += x;
			v |= v + 1;
		}
	}

	int get(int v) {
		int res = 0;
		while (v >= 0) {
			res += a[v];
			v = (v & (v + 1)) - 1;
		}
		return res;
	}
};


vector<ft> a;
vector<vector<int>> tt;

int main() {

#ifdef LOCAL
    freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	vector<qe> q;
	vector<int> xx;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		q.emplace_back(x, y, z);
		xx.pb(z);
	}

	sort(xx.begin(), xx.end());
	xx.resize(unique(xx.begin(), xx.end()) - xx.begin());

	a.resize(xx.size());
	tt.resize(xx.size());
	for (auto &x : q) {
		x.z = lower_bound(xx.begin(), xx.end(), x.z) - xx.begin();
		tt[x.z].pb(x.y);
	}

	for (int i = 0; i < xx.size(); i++) {
		sort(tt[i].begin(), tt[i].end());

		a[i].a.assign(tt[i].size(), 0);
	}

	for (auto &x : q) {
		int t = lower_bound(tt[x.z].begin(), tt[x.z].end(), x.y) - tt[x.z].begin();

		if (x.x == 1) {
			a[x.z].add(t, 1);
		} else if (x.x == 2) {
			a[x.z].add(t, -1);
		} else {
			printf("%d\n", a[x.z].get(t));
		}
	}


    return 0;
}