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
int ls[maxn];
priority_queue<pair<int, int> > q;
map<pair<int, int>, int> ma;
bool used[maxn];

vector<int> ans;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		ma[mp(u, v)] = i;
		rb[u].pb(v);
		ls[v]++;
	}
	for(int i = 1; i <= n; i++) {
		q.push(mp(-ls[i], i));
	}

	while(!q.empty()) {
		int id = q.top().sc;
		q.pop();
		if(used[id]) continue;
		used[id] = 1;
		ans.pb(id);
		for(int i = 0; i < (int)rb[id].size(); i++) {
			ls[rb[id][i]]--;
			q.push(mp(-ls[rb[id][i]], rb[id][i]));
		}
	}

	for(int i = 1; i <= n; i++) if(!used[i]) ans.pb(i);

	int answer = 0;
	for(int i = 1; i < n; i++) {
		if(ma.count(mp(ans[i - 1], ans[i]))) {
			answer = max(answer, ma[mp(ans[i - 1], ans[i])]);
		} else {
			printf("-1");
			return(0);
		}
	}
	printf("%d\n", answer + 1);


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