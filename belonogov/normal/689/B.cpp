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
const int N = 1e6;
const long long INF = 1e9 + 19;

int n;
int dist[N];
vector < int > e[N];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x); x--;
		if (i < x)
			e[i].pb(x);
	}
}

void solve() {
	for (int i = 0; i < n - 1; i++) {
		e[i].pb(i + 1);
		e[i + 1].pb(i);
	}
	queue < int > q;
	q.push(0);
	memset(dist, 63, sizeof(dist));
	dist[0] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u: e[v]) {
			if (dist[u] > dist[v] + 1) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}


	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	puts("");

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