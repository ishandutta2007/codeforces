#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

struct event {
    int x;
    int type;
    ll l, r;
    int ind;
    event(int x, int type, ll a, ll b, int ind) {
        this->x = x;
        this->type = type;
        this->ind = ind;
        l = a, r = b;
    }
    event() {}
};

const int N = 5e5 + 7;
vector <int> cur;
vector <pair <int, int> > g[N];
ll dep[N];
int tin[N];
int tout[N];
int t[N];
ll a[N];
int cnt[N];
vector <event> e[N];
int res[N];
int tt = 1;

int get(int x) {
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        res += t[x];
    }
    return res;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

void inc(int x, int d) {
    for (; x < N; x = (x | (x + 1))) {
        t[x] += d;
    }
}

void dfs(int v, int pr, ll h) {
    dep[v] = h;
    tin[v] = tt++;
    for (auto to : g[v]) {
        if (to.first != pr) {
            dfs(to.first, v, h + to.second);
        }
    }
    tout[v] = tt++;
}

bool cmp(const event &a, const event &b) {
    return a.type < b.type;
}

int main() {
    srand(2);
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
        int pr, w;
        cin >> pr >> w;
        g[i].push_back({pr, w});
        g[pr].push_back({i, w});
    }
    dfs(1, -1, 0);
    vector <ll> all;
    for (int i = 1; i <= n; i++) {
        all.push_back(dep[i]);
        all.push_back(dep[i] - a[i]);
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    for (int i = 1; i <= n; i++) {
        int l = tin[i];
        int r = tout[i];
        ll y = lower_bound(all.begin(), all.end(), dep[i] - a[i]) - all.begin();
        ll z = lower_bound(all.begin(), all.end(), dep[i]) - all.begin();
        e[l].push_back({l, 0, y, y, i});
        e[l - 1].push_back({l - 1, 2, y, z, i});
        e[r].push_back({r, 1, y, z, i});
    }
    for (int i = 0; i < N; i++) {
        sort(e[i].begin(), e[i].end(), cmp);
        for (auto c : e[i]) {
            if (c.type == 0) { // SECOND
                inc(c.l, 1);
            } else if (c.type == 2) { // FIRST
                res[c.ind] = -get(c.r);
            } else if (c.type == 1) {
                res[c.ind] += get(c.r);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i] - 1);
    }
    puts("");
}