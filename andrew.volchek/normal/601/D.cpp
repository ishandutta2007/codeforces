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
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

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


const int maxn = 3e5 + 5;
int a[maxn];
vector<int> g[maxn];
char c[maxn];

vector<int> order;
int parent[maxn];
int sz[maxn];

void dfs(int v, int pr) {
	parent[v] = pr;
	sz[v] = 1;
	for (int to : g[v]) {
		if (to != pr) {
			dfs(to, v);
			sz[v] += sz[to];
		}
	}
	order.pb(v);
}

void merge(vector<int> &a, vector<int> &b) {
	if (a.size() < b.size()) {
		a.swap(b);
	}
	for (int x : b) {
		a.pb(x);
	}
	b.clear();
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

	int n;
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	
	scanf("\n");
	
	for (int i = 0; i < n; i++) {
		scanf("%c", c + i);
	}
	
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(0, -1);
	
	pair<int,int> ans(-1, 0);
	
	for (int v : order) {
	
		queue<int> q;
		q.push(v);
		
		vector<int> visited;
		
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			visited.pb(v);
					
			vector<vector<int>> was(26);
			
			for (int to : g[v]) {
				if (to == parent[v]) {
					continue;
				}
				
				was[c[to] - 'a'].pb(to);
			}
			
			
			g[v].clear();
			for (int j = 0; j < 26; j++) {
				if (was[j].size()) {
					g[v].pb(was[j][0]);
				}
				for (int h = 1; h < was[j].size(); h++) {
					merge(g[was[j][0]], g[was[j][h]]);
				}
				if (was[j].size() > 1) {
					q.push(was[j][0]);
				}
			}
		}
		
		
		reverse(visited.begin(), visited.end());
		
		for (int v : visited) {
			sz[v] = 1;
			for (int to : g[v]) {
				if (to != parent[v]) {
					sz[v] += sz[to];
				}
			}
		}
		
		int cur = sz[v] + a[v];
		
		if (cur > ans.fst) {
			ans = mp(cur, 1);
		} else if (cur == ans.fst) {
			ans.snd++;
		}
	}
	
	cout << ans.fst << "\n" << ans.snd << endl;
	
    return 0;
}