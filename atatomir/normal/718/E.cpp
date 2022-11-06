#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define inf 10000000
#define maxN 100011
#define sigma 8

const int sp = (2 * sigma - 1);
const int lim = (1 << sigma);

int n, i, j;
char s[maxN];
vector<int> wh_col[sigma];
bool color_used[sigma];
queue<int> Q;

int dist[maxN][sigma];
int dist_col[sigma][sigma];

int mask[maxN];
int enabled[sigma][1 << sigma];
int l, r;

ll best, cnt;


void compute_dist(int col) {
    int i;

    memset(color_used, 0, sizeof(color_used));
    while (!Q.empty()) Q.pop();
    for (i = 1; i <= n; i++) dist[i][col] = inf;
    for (auto e : wh_col[col]) dist[e][col] = 0, Q.push(e);

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();

        if (dist[node - 1][col] > dist[node][col] + 1) {
            dist[node - 1][col] = dist[node][col] + 1;
            Q.push(node - 1);
        }

        if (dist[node + 1][col] > dist[node][col] + 1) {
            dist[node + 1][col] = dist[node][col] + 1;
            Q.push(node + 1);
        }

        if (!color_used[s[node] - 'a']) {
            color_used[s[node] - 'a'] = true;
            for (auto e : wh_col[s[node] - 'a']) {
                if (dist[e][col] > dist[node][col] + 1) {
                    dist[e][col] = dist[node][col] + 1;
                    Q.push(e);
                }
            }
        }
    }
}

void compute_dist_col() {
    int i, j, k;

    for (i = 0; i < sigma; i++)
        for (j = 0; j < sigma; j++)
            dist_col[i][j] = (i == j ? 0 : inf);

    for (i = 1; i <= n; i++)
        for (j = 0; j < sigma; j++)
            for (k = 0; k < sigma; k++)
                dist_col[j][k] = min(dist_col[j][k], dist[i][j] + dist[i][k]);
}

void compute_mask() {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < sigma; j++) {
            int dif = dist[i][j] - dist_col[s[i] - 'a'][j];

            if (dif > 1)
                cerr << "error";
            if (dif == 1) mask[i] |= 1 << j;
        }
    }
}

int get_dist(int a, int b) {
    if (a > b) swap(a, b);

    int ans = b - a;
    for (int e = 0; e < sigma; e++)
        ans = min(ans, dist[a][e] + 1 + dist[b][e]);

    return ans;
}

void update_sol(int val, ll how_many) {
    if (how_many == 0) return;

    if (val > best) best = val, cnt = 0;
    if (val == best) cnt += how_many;
}

void go_to_color(int node, int col, int msk) {
    int best = inf;

    if (enabled[col][msk] == 0) return;

    for (int e = 0; e < sigma; e++) {
        int aux_best = dist[node][e] + 1 + dist_col[col][e] + ((msk >> e) & 1);

        best = min(best, aux_best);
    }

    if (best >= inf) return;
    update_sol(best, enabled[col][msk]);
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);

    /*
    n = 100000;
    for (i = 1; i <= n; i++) s[i] = 'a';
    */

    for (i = 1; i <= n; i++)
        wh_col[s[i] - 'a'].pb(i);

    for (i = 0; i < sigma; i++)
        compute_dist(i);

    compute_dist_col();
    compute_mask();

    l = 1; r = min(n, sp + 1);
    for (i = sp + 2; i <= n; i++)
        enabled[s[i] - 'a'][mask[i]]++;

    for (i = 1; i <= n; i++) {
        if (l < i - sp && l < i) {
            enabled[s[l] - 'a'][mask[l]]++;
            l++;
        }

        if (r < i + sp && r < n) {
            r++;
            enabled[s[r] - 'a'][mask[r]]--;
        }

        for (j = l; j <= r; j++)
            update_sol(get_dist(i, j), 1);

        for (j = 0; j < sigma; j++)
            for (int conf = 0; conf < lim; conf++)
                go_to_color(i, j, conf);

    }

    printf("%lld %lld", best, cnt / 2);

    return 0;
}