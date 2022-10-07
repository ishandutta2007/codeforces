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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int c[N];
vector < pair < int, int > > e[N];
int n;
int answer;

void dfs(int v, long long h, long long mnH, bool flag) {
	mnH = min(mnH, h);
	long long val = h - c[v];
	if (val - mnH > 0) {
		flag = 1;	
	}
	answer += flag;
	for (auto x: e[v]) {
		int u = x.fr;
		dfs(u, h + x.sc, mnH, flag);
	}
}

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) {
		int v, c;
		scanf("%d%d", &v, &c); v--;
		e[v].pb(mp(i, c));
	}
}

void solve() {
	dfs(0, 0, 0, 0);
	printf("%d\n", answer);

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