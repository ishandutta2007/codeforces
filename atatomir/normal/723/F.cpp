#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, m, i, x, y, cnt;
vector<int> list[maxN];
int S, T, ds, dt;
bool us[maxN];

int tp[maxN];
int sum[maxN][4];
int leg[maxN][2];

vector< pair<int, int> > ans;

void no_sol() {
    printf("No");
    exit(0);
}

void print_sol() {
    printf("Yes\n");
    for (auto e : ans)
        printf("%d %d\n", e.first, e.second);
    exit(0);
}

void dfs(int node) {
    us[node] = true;

    for (int to : list[node]) {
        if (to == S) tp[cnt] |= 1, leg[cnt][0] = node;
        if (to == T) tp[cnt] |= 2, leg[cnt][1] = node;

        if (us[to]) continue;
        dfs(to);
        ans.pb(mp(node, to));
    }
}

bool can_form(int ds, int dt, int le, int com, int ri) {
    if (le > ds) return false;
    ds -= le; le = 0;

    if (ri > dt) return false;
    dt -= ri; ri = 0;

    if (ds + dt < com) return false;
    return true;
}

void complete_tree(int deny) {
    int i;

    for (i = 1; i <= cnt; i++) {
        if (i == deny) continue;

        if (tp[i] == 1)
            ds--, ans.pb(mp(leg[i][0], S));
    }

    for (i = 1; i <= cnt; i++) {
        if (i == deny) continue;

        if (tp[i] == 2)
            dt--, ans.pb(mp(leg[i][1], T));
    }

    for (i = 1; i <= cnt; i++) {
        if (i == deny) continue;

        if (tp[i] == 3) {
            if (ds) {
                ds--, ans.pb(mp(leg[i][0], S));
            } else {
                dt--, ans.pb(mp(leg[i][1], T));
            }
        }
    }
}

void siblings() {
    int i;
    bool good = false;

    for (auto e : list[S])
        if (e == T)
            good = true;

    if (!good) return;
    if (!can_form(ds - 1, dt - 1, sum[cnt][1], sum[cnt][3], sum[cnt][2])) return;

    ans.pb(mp(S, T));
    ds--; dt--;

    complete_tree(0);
    print_sol();
}

void differ() {
    int i;

    for (i = 1; i <= cnt; i++) {
        if (tp[i] != 3) continue;
        if (!can_form(ds - 1, dt - 1, sum[cnt][1], sum[cnt][3] - 1, sum[cnt][2])) continue;

        ans.pb(mp(S, leg[i][0]));
        ans.pb(mp(leg[i][1], T));
        ds--; dt--;

        complete_tree(i);
        print_sol();
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    scanf("%d%d%d%d", &S, &T, &ds, &dt);
    us[S] = us[T] = true;

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;

        cnt++;
        dfs(i);

        if (tp[cnt] == 0)
            no_sol();

        memcpy(sum[cnt], sum[cnt - 1], sizeof(sum[cnt]));
        sum[cnt][tp[cnt]]++;
    }

    siblings();
    differ();

    no_sol();


    return 0;
}