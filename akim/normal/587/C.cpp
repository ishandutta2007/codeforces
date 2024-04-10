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

vector<int> rb[maxn];
vector<int> st[maxn][20], sst[maxn];
int binup[maxn][20];
int tin[maxn], tout[maxn], t = 0;
bool pm[maxn];

void resz(vector<int> &st, int nsz) {
	while((int)st.size() > nsz) {
		vector<int>::iterator it = st.end();
		it--;
		st.erase(it);
	}
}

vector<int> merge(vector<int> &a, vector<int> &b) {
	vector<int> ret;
//	ret = a;
//	for(vector<int>::iterator it = b.begin(); it != b.end(); it++) {
//		ret.pb(*it);
//	}

	vector<int>::iterator it1 = a.begin(), it2 = b.begin();
	while(it1 != a.end() && it2 != b.end()) {
		if(*it1 < *it2) {
			ret.pb(*it1);
			it1++;
		} else
		if(*it1 > *it2) {
			ret.pb(*it2);
			it2++;
		} else {
			ret.pb(*it1);
			it1++;
			it2++;
		}
	}

	while(it1 != a.end()) {
		ret.pb(*it1);
		it1++;
	}

	while(it2 != b.end()) {
		ret.pb(*it2);
		it2++;
	}

//	sort(ret.begin(), ret.end());
//	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return(ret);
}

vector<int> getancestor(int a, int b) {
	vector<int> ans = merge(sst[a], sst[b]);
	resz(ans, 10);

	for(int i = 19; i >= 0; i--) {
		if(tin[binup[b][i]] <= tin[a] && tout[a] <= tout[binup[b][i]]) {

		} else {
			ans = merge(ans, st[b][i]);
			resz(ans, 10);
			b = binup[b][i];
		}
	}
	ans = merge(ans, st[b][0]);
	resz(ans, 10);
	b = binup[b][0];

	swap(a, b);

	for(int i = 19; i >= 0; i--) {
		if(tin[binup[b][i]] <= tin[a] && tout[a] <= tout[binup[b][i]]) {

		} else {
			ans = merge(ans, st[b][i]);
			resz(ans, 10);
			b = binup[b][i];
		}
	}
	ans = merge(ans, st[b][0]);
	resz(ans, 10);
	b = binup[b][0];
	return(ans);
}

vector<int> getancestor2(int a, int b) {
	vector<int> ans = merge(sst[a], sst[b]);
	resz(ans, 10);

	for(int i = 19; i >= 0; i--) {
		if(tin[binup[b][i]] <= tin[a] && tout[a] <= tout[binup[b][i]]) {

		} else {
			ans = merge(ans, st[b][i]);
			resz(ans, 10);
			b = binup[b][i];
		}
	}
	ans = merge(ans, st[b][0]);
	resz(ans, 10);
	b = binup[b][0];
	return(ans);
}

vector<int> get(int a, int b) {

	if(a == b) {
		return(sst[a]);
	}

	if(tin[a] > tin[b]) {
		swap(a, b);
	}
	if(tin[a] <= tin[b] && tout[b] <= tout[a]) {
		return(getancestor2(a, b));
	}

	return(getancestor(a, b));

}


void dfs(int u) {
	tin[u] = t++;
	pm[u] = 1;

	for(int i = 1; i < 20; i++) {
		binup[u][i] = binup[binup[u][i - 1]][i - 1];
		st[u][i] = merge(st[u][i - 1], st[binup[u][i - 1]][i - 1]);
		resz(st[u][i], 10);
	}

	for(int i = 0; i < (int)rb[u].size(); i++) {
		if(pm[rb[u][i]]) continue;
		binup[rb[u][i]][0] = u;
		st[rb[u][i]][0] = sst[u];
		dfs(rb[u][i]);
	}
	tout[u] = t++;
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		rb[u].pb(v);
		rb[v].pb(u);
	}
	for(int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		sst[x].pb(i);
	}

	for(int i = 1; i <= n; i++) {
		sort(sst[i].begin(), sst[i].end());
		resz(sst[i], 10);
	}


	binup[1][0] = 1;
	dfs(1);

	for(; q > 0; q--) {
		int u, v, a;
		scanf("%d%d%d", &u, &v, &a);
		vector<int> st = get(u, v);
		resz(st, a);

		printf("%d ", (int)st.size());
		while(!st.empty()) {
			printf("%d ", *st.begin());
			st.erase(st.begin());
		}
		printf("\n");
	}

	return(0);
}

// by Kim Andrey