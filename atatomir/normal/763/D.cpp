#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

const ll mod1 = 1000000007;
const ll base1 = 31;
const ll mod2 = 1000000009;
const ll base2 = 37;

ll poww1[maxN], poww2[maxN];

struct hsh {
    ll h1, h2;

    hsh operator<<(int x) {
        return {(h1 * poww1[x]) % mod1, (h2 * poww2[x]) % mod2};
    }

    hsh operator+(hsh who) {
        who.h1 += h1;
        who.h2 += h2;

        if (who.h1 >= mod1) who.h1 -= mod1;
        if (who.h2 >= mod2) who.h1 -= mod2;

        return who;
    }

    hsh operator+(ll x) {
        return {(h1 + x) % mod1, (h2 + x) % mod2};
    }

};


int n, i, x, y;
vector<int> list[maxN];
ll down[maxN], up[maxN];
hsh aux;

vector< pair<ll, int> > ord;
hsh le[maxN], ri[maxN];

map<ll, int> M;
int ans, ans_max;
int nn;


void dfs_down(int node, int root) {
    int i;

    for (i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        if (to == root) {
            list[node][i] = list[node].back();
            list[node].pop_back();
            i--; continue;
        }

        dfs_down(to, node);
    }

    down[node] = 0;
    sort(list[node].begin(), list[node].end(), [](int a, int b)->bool const {
        return down[a] < down[b];
    });

    aux = {0, 0};
    for (auto e : list[node])
        aux = (aux << 1) + down[e];

    down[node] = (aux.h1 << 31) | (aux.h2 << 1) | 1;
}

void dfs_up(int node) {
     int i;

    ord.clear();
    if (node != 1) ord.pb(mp(up[node], -1));

    for (auto to : list[node])
        ord.pb(mp(down[to], to));

    if (ord.empty())
        return;

    sort(ord.begin(), ord.end());

    le[0] = {ord[0].first % mod1, ord[0].first % mod2};
    for (i = 1; i < ord.size(); i++)
        le[i] = (le[i - 1] << 1) + ord[i].first;

    ri[ord.size() - 1] = {ord.back().first % mod1, ord.back().first % mod2};
    for (i = ord.size() - 2; i >= 0; i--)
        ri[i] = ri[i + 1] + ((hsh){ord[i].first % mod1, ord[i].first % mod2} << (ord.size() - i - 1));

    for (i = 0; i < ord.size(); i++) {
        aux = {0, 0};

        if (i != 0)
            aux = le[i - 1] << (ord.size() - i - 1);
        if (i != ord.size() - 1)
            aux = aux + ri[i + 1];

        if (ord[i].second == -1) continue;
        up[ord[i].second] = (aux.h1 << 31) | (aux.h2 << 1) | 1;
    }

    for (auto to : list[node])
        dfs_up(to);
}

void add(ll who) {
    if (M[who] == 0) ans++;
    M[who]++;
}

void rm(ll who) {
    if (M[who] == 1) ans--;
    M[who]--;
}

void solve(int node) {
    if (ans > ans_max) nn = node;
    ans_max = max(ans_max, ans);

    for (auto to : list[node]) {
        rm(down[to]);
        add(up[to]);

        solve(to);

        add(down[to]);
        rm(up[to]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    poww1[0] = poww2[0] = 1;
    for (i = 1; i <= n; i++) {
        poww1[i] = (poww1[i - 1] * base1) % mod1;
        poww2[i] = (poww2[i - 1] * base2) % mod2;
    }

    dfs_down(1, 0);
    dfs_up(1);

    for (i = 2; i <= n; i++) add(down[i]);
    ans_max = ans;
    nn = 1;

    solve(1);

    printf("%d", nn);



    return 0;
}