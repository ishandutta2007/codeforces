#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
const int INF = 1e9 + 19;

bool cmp (pair < int, int > a, pair < int, int > b) {
    return a.fr > b.fr || (a.fr == b.fr && a.sc < b.sc);
}

int n;
vector < pair < int, int > > e[N];
int use[N];
int center;
long long answer;
vector < int > data;
int st[N];
int fn[N];
int tree[N * 4];
int rev[N];
set < pair < int, int >, bool (*) (pair < int, int >, pair < int, int > )> q(cmp);
int cnt[N];
int pos[N];

void read() {
        scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--;
        e[v].pb(mp(u, c));
        e[u].pb(mp(v, c));
    }
}

int dfs0(int v) {
    use[v] = 1;
    int cnt = 0;
    int mx = 0;
    for (auto x: e[v]) 
        if (!use[x.fr]) {
            int tmp = dfs0(x.fr);
            mx = max(tmp, mx);
            cnt += tmp;
        }
    mx = max(mx, n - 1 - cnt);
    if (mx * 2 <= n) 
        center = v;
    return cnt + 1;

}

void dfs1(int v, long long h) {
    use[v] = 1;
    answer += h * 2;
    for (auto x: e[v])
        if (!use[x.fr])
            dfs1(x.fr, h + x.sc);
}

void dfs2(int v) {
    use[v] = 1;
    data.pb(v);
    for (auto x: e[v])
        if (!use[x.fr])
            dfs2(x.fr);
}

void build(int v, int ll, int rr) {
    if (ll + 1 == rr) {
        tree[v] = data[ll]; 
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int get(int v, int ll, int rr, int l, int r) {
    if (ll >= r || l >= rr) return INF;
    if (l <= ll && rr <= r) 
        return tree[v];
    return min(get(v * 2 + 1, ll, (ll + rr) / 2, l, r), 
               get(v * 2 + 2, (ll + rr) / 2, rr, l, r));
}

void setT(int v, int ll, int rr, int pos, int val) {
    if (pos < ll || rr <= pos) return;
    if (ll + 1 == rr) {
        tree[v] = val;
        return;
    }
    setT(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
    setT(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}


pair < long long, vector < int > > solve() {
    answer = 0;
    q.clear();
    memset(use, 0, sizeof(use));

    center = -1;
    dfs0(0);
    assert(center != -1); 

    memset(use, 0, sizeof(use));
    dfs1(center, 0);
    memset(use, 0, sizeof(use));

    vector < pair < vector < int >, int > > subTree;

    use[center] = 1;
    subTree.pb(mp(vector < int > (1, center), center));

    for (auto x: e[center]) {
        data.clear();
        dfs2(x.fr);
        subTree.pb(mp(data, x.fr));
    }
    int cur = 0;
    data.resize(n);
    for (auto & x: subTree) {
        st[x.sc] = cur;
        cnt[x.sc] = x.fr.size();
        cur += cnt[x.sc];
        fn[x.sc] = cur; 
        for (int i = 0; i < (int)x.fr.size(); i++) {
            data[i + st[x.sc]] = x.fr[i];
            rev[x.fr[i]] = x.sc;
        }
        q.insert(mp(cnt[x.sc] * 2, x.sc)); 
    }
    assert(cur == n);   
    for (int i = 0; i < n; i++) {
        pos[data[i]] = i;
        cnt[i] *= 2;
    }
    build(0, 0, n);
    vector < int > ans(n, -1);
    for (int i = 0; i < n; i++) {
        int all = n - i;
        int type = rev[i];
        int x;
        auto g = q.begin(); 
        if ((int)q.size() >= 2 && g->sc == center) {
            auto it = q.begin();
            it++;
            if (it->fr == g->fr)
                g = it;
        }
        if (g->fr == all && g->sc != type && g->sc != center) {
            x = get(0, 0, n, st[g->sc], fn[g->sc]);
        }
        else {
            if (i == center)
                x = get(0, 0, n, 0, n);
            else
                x = min(get(0, 0, n, 0, st[type]), get(0, 0, n, fn[type], n));      
        }
        ans[i] = x;  
        setT(0, 0, n, pos[x], INF);
        assert(q.count(mp(cnt[rev[i]], rev[i])) == 1);
        q.erase(mp(cnt[rev[i]], rev[i]));
        cnt[rev[i]]--;
        q.insert(mp(cnt[rev[i]], rev[i]));

         
        assert(q.count(mp(cnt[rev[x]], rev[x])) == 1);
        q.erase(mp(cnt[rev[x]], rev[x]));
        cnt[rev[x]]--;
        q.insert(mp(cnt[rev[x]], rev[x]));

    }
    return mp(answer, ans);
}

void printAns(pair < long long, vector < int > > ans) {
    cout << ans.fr << "\n";
    for (auto x: ans.sc)
        printf("%d ", x + 1);
    printf("\n");
}


int main(){
    read();
    printAns(solve());
}