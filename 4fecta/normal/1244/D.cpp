#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;
int n, u, v;
int c[MN][3];
int prm[6][3] = {{0, 1, 2},
                 {0, 2, 1},
                 {1, 0, 2},
                 {1, 2, 0},
                 {2, 0, 1},
                 {2, 1, 0}};
vector<int> a[MN];
ll mini = LONG_LONG_MAX >> 3;
int ans[MN];

void dfs(int cur, int par, int d, int num, ll sum, int seq[MN]) {
    sum += c[cur][prm[num][d % 3]];
    //printf("%d\n", c[cur][prm[num][d % 3]]);
    seq[cur] = prm[num][d % 3] + 1;
    //printf("%lld\n", sum);
    if (a[cur].size() == 1 && par > 0) {
        if (sum < mini) {
            mini = sum;
            for (int i = 1; i <= n; i++) {
                //printf("%d ", seq[i]);
                ans[i] = seq[i];
            }
            //printf("\n");
        }
        return;
    }
    for (int i : a[cur]) {
        if (i == par) continue;
        dfs(i, cur, d + 1, num, sum, seq);
    }
}

int main() {
    boost();

    cin >> n;

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[j][i];
        }
    }

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        if (a[u].size() > 2 || a[v].size() > 2) {
            printf("-1\n");
            return 0;
        }
    }

    int st = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i].size() == 1) {
            st = i;
            break;
        }
    }
    int te[MN];
    for (int i = 0; i < 6; i++) {
        dfs(st, -1, 0, i, 0, te);
        //printf("\n");
    }

    printf("%lld\n", mini);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}