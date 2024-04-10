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

const int maxn = 1005;
const int maxm = 1e6 + 5;

struct edge {
    int u, v, w;
    int id;
    bool operator < (const edge &rhs) const {
        return w < rhs.w;
    }
};

int comp[maxn];
int sz[maxn];
int color[maxn];
vector<int> s[maxn];

edge e[maxm];

void gen() {
  //  ofstream out("a.in")
  //  int n = 1000, m = 500 * 500, q = 1000;

}

int main() {

#ifdef LOCAL
	freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    //n = 1000, m = 500, q = 1000;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        e[i].id = i;
    }


    sort(e + 1, e + m + 1);

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        //l = 1, r = m;
        iota(comp + 1, comp + 1 + n, 1);
        fill(sz + 1, sz + 1 + n, 1);
        fill(color + 1, color + 1 + n, 0);
        for (int j = 1; j <= n; j++) {
            s[j].clear();
            s[j].pb(j);
        }


        int ans = -1;
        int iter = 0;
        for (int j = m; j >= 1; j--) {
        
            if (!(l <= e[j].id && e[j].id <= r)) {
                continue;
            }

            int x = e[j].u, y = e[j].v;
            if (comp[x] == comp[y]) {
                if (color[x] == color[y]) {
                    ans = e[j].w;
                    break;
                }
            } else {
                if (sz[comp[x]] > sz[comp[y]]) {
                    swap(x, y);
                }

                if (color[x] == color[y]) {
                    for (int h : s[comp[x]]) {
                        color[h] ^= 1;
                    }
                }

                int g = comp[x];
                for (int h : s[g]) {
                    comp[h] = comp[y];
                    s[comp[y]].pb(h);
                }

                sz[comp[y]] += sz[g];
                s[g].clear();
            }
        }

        cout << ans << endl;
    }






	return 0;
}