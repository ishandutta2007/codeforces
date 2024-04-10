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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 3010;

bool pm[maxn][maxn];
int ms[maxn][maxn];
vector<int> rb[maxn];
vector<pair<int, pair<int, int> > > vc;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	for(int g = 0; g < n; g++) {
		vc.clear();
		vc.pb(mp(g, mp(g, 0)));
		pm[g][g] = 1;
		for(int i = 0; i < (int)vc.size(); i++) {
			int u = vc[i].fs, v = vc[i].sc.fs, c = vc[i].sc.sc;
			ms[u][v] = c;
			for(int f = 0; f < (int)rb[v].size(); f++) {
				if(!pm[u][rb[v][f]]) {
					pm[u][rb[v][f]] = 1;
					vc.pb(mp(u, mp(rb[v][f], c + 1)));
				}
			}
		}
	}
	int s1, t1, l1;
	scanf("%d%d%d", &s1, &t1, &l1); s1--, t1--;
	int s2, t2, l2;
	scanf("%d%d%d", &s2, &t2, &l2); s2--, t2--;

	if(ms[s1][t1] > l1 || ms[s2][t2] > l2) {
		printf("-1");
		return(0);
	}
	int ans = ms[s1][t1] + ms[s2][t2];
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < n; f++) {
			if(ms[s1][i] + ms[i][f] + ms[f][t1] <= l1 && ms[s2][i] + ms[i][f] + ms[f][t2] <= l2)
				ans = min(ans, ms[s1][i] + ms[f][t1] + ms[i][f] + ms[s2][i] + ms[f][t2]);
			if(ms[s1][i] + ms[i][f] + ms[f][t1] <= l1 && ms[s2][f] + ms[i][f] + ms[i][t2] <= l2)
							ans = min(ans, ms[s1][i] + ms[f][t1] + ms[i][f] + ms[s2][f] + ms[i][t2]);
		}
	}
	printf("%d",m - ans);

	return(0);
}

// by Kim Andrey