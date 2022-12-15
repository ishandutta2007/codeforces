#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef long double llf;
typedef unsigned long long llu;
const int INF = 987654321;
const ll LINF = 1e15;

const int N_ = 150005;

int N;
vector<int> Gph[N_], Rev[N_];
int deg[N_];

bool chk[N_];

int Res[N_];
int used[N_];

int sz;

void solve (int u) {
	chk[u] = 1;
	for(int i = 0; i < Gph[u].size(); i++) {
		int v = Gph[u][i]; if(chk[v]) continue;
		solve(v);

		bool brk = false;
		for(int c = 26; c > 0 && !brk; c--) {
			if(used[u] & used[v] & (1<<(c-1))) used[u] |= (1<<(c-1))-1, brk = 1;
		}

		used[u] |= used[v];
	}

	++used[u];
	for(int b = 29; b >= 1; b--) if(used[u] & (1<<(b-1))) {
		if(sz < b) sz = b;
		break;
	}

	for(int b = 1; b <= 29; b++) if(used[u] & (1<<(b-1))) {
		Res[u] = b;
		break;
	}
}

int main() {
    int i, j, k;

    scanf("%d", &N);
    for(i = 1; i < N; i++) {
    	int u, v; scanf("%d%d", &u, &v);
    	int up = Gph[u].size(), vp = Gph[v].size();
    	Gph[u].push_back(v); Rev[u].push_back(vp); ++deg[u];
    	Gph[v].push_back(u); Rev[v].push_back(up); ++deg[v];
    }

    int root;
    for(root = 1; root <= N; root++) if(deg[root] == 1) break;

    solve(root);

    if(sz > 27) return 0 & puts("Impossible!");
    //for(i = 1; i <= N; i++) printf("%c ", Res[i]+'A'-1);
    for(i = 1; i <= N; i++) printf("%c ", 'Z'+1-Res[i]);
    return 0;
}