#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-17;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;
int need[201];
bool used[201];
vector<int> vec[4], v[201];
int need_more[201];

inline void check(int t) {
	if (need_more[t] == 0) {
		vec[need[t]].push_back(t);
		need_more[t] = -1;
	}
}

void solve(int pos) {
	if (used[pos])
		return;
	used[pos] = true;
	for (int i = 0; i < (int) v[pos].size(); i++) {
		need_more[v[pos][i]]--;
		check(v[pos][i]);
	}
}

vector<int> tt[201];

int _solve(int start) {
	ms(used);
	for (int i = 1; i <= n; i++)
		need_more[i] = tt[i].size();
	int ans = n - 1;
	int played = 0;
	for (int i = 1; i <= n; i++)
		check(i);
	int e = 0;
	for (int i = start; played < n; i = (i == 3 ? 1 : i + 1), ans++) {
		e++;
		while (!vec[i].empty()) {
			e = 0;
			int a = vec[i].back();
			vec[i].pop_back();
			solve(a);
			played++;
		}
		if (e > 5) {
			cout << "!" << endl;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
		vec[i].clear();
	return ans;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> need[i];
	}

	for(int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		set<int> s;
		for(int j = 0; j < w; j++) {
			int a;
			cin >> a;
			if(s.find(a) != s.end())
			continue;
			s.insert(a);
			tt[i].push_back(a);
			v[a].push_back(i);
		}
	}
	int ans = INT_MAX;
	for(int i = 1; i <= 3; i++)
	ans = min(ans, _solve(i));
	cout << ans << endl;

}