#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <fstream>
#include <stack>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double

template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
	return x * x;
}

template<typename T>
ostream& operator << (ostream &s, const vector<T> &x) {
	s << "[";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "]";
	return s;
}

template<typename T>
ostream& operator << (ostream &s, const set<T> &x) {
	s << "{";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "}";
	return s;
}


template<typename U, typename V>
ostream& operator << (ostream &s, const pair<U, V> &x) {
	s << "(" << x.fst << ", " << x.snd << ")";
	return s;
}

template<typename T>
bool chmax(T &x, const T &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

template<typename T>
bool chmin(T &x, const T &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

//---------------------------------------------------------------------

const int maxn = 1003;

vector < int > g[maxn];

bool used[maxn];

void dfs(int v) {
	used[v] = true;
	for (auto to : g[v]) {
		if (used[to])
			continue;
		dfs(to);
	}
}

int main() {
	//srand(time(NULL));
	#ifdef LOCAL
		//gen();
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#else
		//freopen("springs.in", "r", stdin);
		//freopen("springs.out", "w", stdout);
	#endif
	//check();
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	int n, m;
	cin >> n >> m;
	if (m != n - 1) {
		cout << "no\n";
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			dfs(i);
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << "no\n";
	}
	else {
		cout << "yes\n";
	}

	return 0;
}