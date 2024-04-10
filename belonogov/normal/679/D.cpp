#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 444;
const long long INF = 1e9 + 19;

int n, m;
int a[N][N];
vector < int > e[N];
double cof[N];
int use[N];
int tmr;
//double sum[N];
double mx[N];

void read() {
	scanf("%d%d", &n, &m);
	memset(a, 63, sizeof(a));
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		e[v].pb(u);
		e[u].pb(v);
		a[v][u] = a[u][v] = 1;
	}
}

void solve() {
	for (int i = 0; i < n; i++)
		a[i][i] = 0;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

	//for (int i = 0; i < n; i++, cerr << endl)
		//for (int j = 0; j < n; j++)
			//cerr << a[i][j] << " ";
	
	double answer = 0;


	for (int f = 0; f < n; f++) {
		vector < vector < int > > g(n);
		for (int i = 0; i < n; i++)
			g[a[f][i]].pb(i);

		double res = 0;
		for (int d = 0; d < n; d++) {
			if (g[d].empty()) continue;
			if (g[d].size() == 1) {
				res += 1.0 / n;
				continue;
			}
			double best2 = 1.0 / n;

			for (int i = 0; i < n; i++) 
				cof[i] = 0;
			tmr++;
			for (auto v: g[d]) {
				for (auto u: e[v]) {
					cof[u] += 1.0 / n / e[v].size();
					use[u] = tmr;
				}
			}
			vector < int > who;
			for (int i = 0; i < n; i++)
				if (use[i] == tmr)
					who.pb(i);

			for (int s = 0; s < n; s++) {
				double res2 = 0;
				tmr++;
				for (auto v: who) {
					int d = a[s][v];
					if (use[d] != tmr) {
						use[d] = tmr;
						//sum[d] = 0;
						mx[d] = 0;
					}
					//sum[d] += cof[v];
					mx[d] = max(mx[d], cof[v]);
				}		
				tmr++;
				for (auto v: who) {
					int d = a[s][v];
					if (use[d] != tmr) {
						use[d] = tmr;
						//assert(sum[d] > 0);
						res2 += mx[d];
					}
				}
				best2 = max(best2, res2);
			}
			res += best2;
		}



		answer = max(answer, res);

	}

	printf("%.17f\n", answer);

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}