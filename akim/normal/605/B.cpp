#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int a[maxn], b[maxn];
int c[maxn];
int u[maxn], v[maxn];

bool cmp(int x, int y) {
	if(b[x] != b[y]) {
		return(b[x] > b[y]);
	}
	return(a[x] < a[y]);
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n, m, q = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		c[i] = i;
		q += b[i];
	}

	if(q != n - 1) {
		printf("-1");
		return(0);
	}

	sort(&c[0], &c[m], cmp);

	int k = n - 1;
	for(int i = 0; i < k; i++) {
		int &j = c[i];
		u[j] = 1, v[j] = i + 2;
	}
	if(k < m) {
		priority_queue<pair<int, pair<int, int> > > q;
		for(int i = 0; i < k - 1; i++) {
			q.push(mp(-(max(a[c[i]], a[c[i + 1]])), mp(i + 2, i + 3)));
		}
		for(int i = k; i < m; i++) {
			if(q.empty()) {
				printf("-1");
				return(0);
			}
			int &j = c[i];
			pair<int, pair<int, int> > p = q.top();
			q.pop();
			cerr << -p.fs << " " << a[j] << endl;
			if(-p.fs > a[j]) {
				printf("-1");
				return(0);
			}
			u[j] = p.sc.fs, v[j] = p.sc.sc;
			if(v[j] + 1 <= n) q.push(mp(-(max(a[c[u[j] - 2]], a[c[v[j] + 1 - 2]])), mp(u[j], v[j] + 1)));
		}
	}

	for(int i = 0; i < m; i++) {
		printf("%d %d\n", u[i], v[i]);
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim