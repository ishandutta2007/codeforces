#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//																														tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

void initialization() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(__rdtsc());
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	finish(solution());
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 2200;

string s[maxn], t[maxn];
int ss[maxn], tt[maxn], id;
string rid[maxn];
map<int, int> ma;
map<string, int> sd;

int mt[maxn], used[maxn];
vector<int> rb[maxn];

bool kuhn(int v) {
	if (used[v])
		return false;
	used[v] = true;
	for (size_t i = 0; i < rb[v].size(); ++i) {
		int to = rb[v][i];
		if (mt[to] == -1 || kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
		string s1; // = s[i][0] + s[i][1] + s[i][2];
		string s2; // = s[i][0] + s[i][1] + t[i][0];
		s1.pb(s[i][0]), s1.pb(s[i][1]), s1.pb(s[i][2]);
		s2.pb(s[i][0]), s2.pb(s[i][1]), s2.pb(t[i][0]);
		s[i] = s1, t[i] = s2;
		ss[i] = sd.count(s[i]) ? sd[s[i]] : sd[s[i]] = id++;
		rid[ss[i]] = s[i];
		tt[i] = sd.count(t[i]) ? sd[t[i]] : sd[t[i]] = id++;
		rid[tt[i]] = t[i];
		ma[ss[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (ma[ss[i]] == 1) {
			rb[ss[i]].pb(i);
		}
		rb[tt[i]].pb(i);
	}

	int cnt = 0;
	memset(mt, -1, sizeof(mt));
	for (int v = 0; v < id; v++) {
		memset(used, 0, sizeof(used));
		cnt += kuhn(v);
	}
	if (cnt != n) {
		printf("NO");
	} else {
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			printf("%s\n", rid[mt[i]].c_str());
		}
	}



	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim