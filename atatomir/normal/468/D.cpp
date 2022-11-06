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

#define maxN 100011
#define lSon (node << 1)
#define rSon (lSon | 1)
#define inf 1000000000

struct aint {
    int dim;
    pair<int, int> data[maxN * 4 + 11];
    int add[maxN * 4 + 11];

    void build(int node, int l, int r) {
        if (l == r) {
            data[node] = mp(0, l);
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
        data[node] = min(data[lSon], data[rSon]);
    }

    void init(int _dim) {
        dim = _dim;
        build(1, 1, dim);
    }

    void upd(int node, int l, int r, int qL, int qR, int v) {
        if (qL > qR) return;
        if (qL <= l && r <= qR) {
            add[node] += v;
            data[node].first += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, v);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, v);
        data[node] = min(data[lSon], data[rSon]);
        data[node].first += add[node];
    }

    pair<int, int> que(int node, int l, int r, int qL, int qR) {
        if (qL > qR) return mp(inf, 0);
        if (qL <= l && r <= qR)
            return data[node];

        int mid = (l + r) >> 1;
        auto ans = mp(inf, 0);
        if (qL <= mid) ans = min(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid) ans = min(ans, que(rSon, mid + 1, r, qL, qR));
        return mp(ans.first + add[node], ans.second);
    }
};

int n, i, x, y, z, R, gr;
vector< pair<int, int> > list[maxN];
int cnt[maxN], p[maxN];
bool us[maxN];
ll ans;

aint work;
aint mini;
vector<int> who[maxN];
int where[maxN];

void dfs(int node, int root) {
    cnt[node] = 1;

    for (auto to : list[node])
        if (to.first != root)
            dfs(to.first, node), cnt[node] += cnt[to.first];
}

void dfs2(int node, int root, int target) {
    bool ok = (target - cnt[node] <= target / 2);

    for (auto to : list[node]) {
        if (to.first == root) continue;
        dfs2(to.first, node, target);
        if (cnt[to.first] > target / 2) ok = false;
    }

    if (ok) R = node;
}

void dfs3(int node, int root, ll act) {
    ans += 2LL * act;

    for (auto to : list[node])
        if (to.first != root)
            dfs3(to.first, node, act + to.second);
}

void dfs4(int node, int root) {
    who[gr].pb(node);
    where[node] = gr;
    for (auto to : list[node])
        if (to.first != root)
            dfs4(to.first, node);
}

void solve(int act) {
    int match, match_gr;

    if (act == R) {
        //! act node is the root
        if (work.data[1].first == 0) {
            //! we must pick from a group
            match_gr = work.data[1].second;
            match = who[match_gr].back();
        } else {
            //! we can choose the group
            match_gr = mini.data[1].second;
            match = mini.data[1].first;
            if (!us[R] && R < match) {
                match_gr = 0;
                match = R;
            }
        }
    } else {
        //! act node is not the root
        auto aux = min(work.que(1, 1, gr, 1, where[act] - 1),
                       work.que(1, 1, gr, where[act] + 1, gr));
        auto aux2 =  min(mini.que(1, 1, gr, 1, where[act] - 1),
                         mini.que(1, 1, gr, where[act] + 1, gr));

        if (aux.first == 0) {
            //! we must pick from a group
            match_gr = aux.second;
            match = who[match_gr].back();
        } else {
            //! we can choose the group
            match_gr = aux2.second;
            match = aux2.first;
            if (!us[R] && R < match) {
                match_gr = 0;
                match = R;
            }
        }
    }

    if (match == R) {
        //! we chose the root
        p[act] = R;
        us[R] = true;
        work.upd(1, 1, gr, 1, gr, -1);
    } else {
        //! we didn't choose the root
        p[act] = match;
        us[match] = true;

        work.upd(1, 1, gr, 1, gr, -1);
        work.upd(1, 1, gr, match_gr, match_gr, +1);

        if (who[match_gr].size() == 1) {
            who[match_gr].pop_back();
            mini.upd(1, 1, gr, match_gr, match_gr, + inf);
        } else {
            who[match_gr].pop_back();
            mini.upd(1, 1, gr, match_gr, match_gr, who[match_gr].back() - match);
        }
    }


    if (act == R) {
        //! we are in the root
        //! nothing...
    } else {
        //! we are not in the root
        work.upd(1, 1, gr, where[act], where[act], +1);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
    }

    if (n == 1) {
        printf("0\n1");
        return 0;
    }

    dfs(1, 0);
    dfs2(1, 0, cnt[1]);
    dfs3(R, 0, 0);

    for (auto to : list[R]) {
        gr++;
        dfs4(to.first, R);
        sort(who[gr].begin(), who[gr].end());
        reverse(who[gr].begin(), who[gr].end());
    }

    work.init(gr);
    work.upd(1, 1, gr, 1, gr, +1);
    mini.init(gr);

    for (i = 1; i <= gr; i++) {
        work.upd(1, 1, gr, 1, gr, who[i].size());
        work.upd(1, 1, gr, i, i, - 2 * who[i].size());
        mini.upd(1, 1, gr, i, i, who[i].back());
    }

    for (i = 1; i <= n; i++)
        solve(i);

    printf("%lld\n", ans);
    for (i = 1; i <= n; i++) printf("%d ", p[i]);


    return 0;
}