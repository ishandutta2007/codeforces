#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

struct state {
	int x, y, z;
	state() : x(0), y(0), z(0) {}
	state(int x, int y, int z) : x(x), y(y), z(z) {}
};

int N, K;
int w[55];
int dp[55][55][2];
int ways[55][55][2];
int choose[55][55];
int a, b;
queue <state> Q;

inline int mul(int x, int y) { 
    return (ll)x * y % MOD;
}

inline int add(int x, int y) {
    return (x + y) % MOD;
}

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) 
        scanf("%d", w + i);
}

void init() {
	choose[0][0] = 1;
    for (int i = 1; i < 55; i++) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++)
            choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
    }
    int g = 100;
    for (int i = 0; i < N; i++) 
        g = __gcd(g, w[i]);
    K /= g;
    for (int i = 0; i < N; i++) {
        w[i] /= g; 
        if (w[i] == 1) a++;
        else b++;
    }
}

int f(state c) {
	int &ref = ways[c.x][c.y][c.z];
	if (ref != -1) return ref;
	ref = 0;
	for (int i = 0; i <= c.x; i++) 
    	for (int j = 0; j <= c.y; j++) 
    		if (i + j && i + j * 2 <= K) {
    			state prev(a - c.x + i, b - c.y + j, c.z ^ 1);
    			if (dp[c.x][c.y][c.z] == dp[prev.x][prev.y][prev.z] + 1) 
    				ref = add(ref, mul(f(prev), mul(choose[prev.x][i], choose[prev.y][j])));
    		}
    return ref;
}

void solve() {
    if (!K) {
        puts("-1\n0");
        return;
    }
    if (K == 1) {
        puts(N > 1 ? "-1\n0" : "1\n1");
        return;
    }
    
    memset(dp, INF, sizeof dp);
    memset(ways, -1, sizeof ways);
    dp[a][b][0] = 0;
    ways[a][b][0] = 1;
    Q.push(state(a, b, 0));
	
    while (!Q.empty()) {
    	state c = Q.front();
    	Q.pop();
    	for (int i = 0; i <= c.x; i++) 
    		for (int j = 0; j <= c.y; j++) 
    			if (i + j && i + j * 2 <= K) {
    				state nxt(a - c.x + i, b - c.y + j, c.z ^ 1);
    				int &ref = dp[nxt.x][nxt.y][nxt.z];
    				if (ref != INF) continue;
    				ref = dp[c.x][c.y][c.z] + 1;
    				Q.push(nxt);
    			}
    }
    
    printf("%d\n%d\n", dp[a][b][1] == INF ? -1 : dp[a][b][1], f(state(a, b, 1)));
}

int main() {
    load();
    init();
    solve();
    return 0;
}