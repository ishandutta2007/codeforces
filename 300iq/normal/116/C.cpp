#include <vector>
#include <stdio.h>

using namespace std;

int g[2005][2005];
int OK[2005][2005];
bool used[2005];
int n;
int tin[2005];
int tout[2005];
int tt = 0;

void calc_time(int v) {
    tin[v] = ++tt;
    used[v] = 1;
    for (int i = 1; i <= n; i++) {
	if (!used[i] && g[v][i]) {
	    calc_time(i);
	}
    }
    tout[v] = ++tt;
}

bool isAnc(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

void find_comps(int v) {
    used[v] = 1;
    for (int i = 1; i <= n; i++)
	if (OK[v][i] && !used[i]) {
	    for (int j = 1; j <= n; j++)
		if (OK[v][j] == 0) OK[i][j] = OK[j][i] = 0;	
	    find_comps(i);
	    for (int j = 1; j <= n; j++)
		if (OK[i][j] == 0) OK[v][j] = OK[j][v] = 0;
	}
}

int main() {
    for (int i = 0; i < 2005; i++)
	for (int j = 0; j < 2005; j++)
	    OK[i][j] = 1;
    scanf("%d", &n);
    int p;
    vector <int> d;
    for (int i = 1; i <= n; i++) {
	scanf("%d", &p);
	if (p != -1) {
	    g[i][p] = g[p][i] = 1;
	} else {
	    d.push_back(i);
	}
    }
    for (int i = 0; i < (int) d.size(); i++) {
	calc_time(d[i]);
    }
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
		if (isAnc(i, j)) {
		    OK[i][j] = OK[j][i] = 0;
		}
	}
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
	used[i] = 0;
    for (int i = 1; i <= n; i++) {
	if (!used[i]) {
	    find_comps(i);
	    ans++;
	}
    }
    printf("%d\n", ans);
}