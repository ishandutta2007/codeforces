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

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int c[maxn];



int main() {

#ifdef LOCAL
	freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    fill(c, c + maxn, -1);

    for (int i = 1; i <= n; i++) {
        if (c[i] == -1) {
            c[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int to : g[v]) {
                    if (c[to] == -1) {
                        c[to] = !c[v];
                        q.push(to);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int to : g[i]) {
            if (c[i] == c[to]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<int> a[2];
    for (int i = 1; i <= n; i++)  {
        a[c[i]].pb(i);
    }

    for (int i = 0; i < 2; i++) {
        printf("%d\n", a[i].size());
        for (int x : a[i]) {
            printf("%d ", x);
        }
        printf("\n");
    }


	return 0;
}