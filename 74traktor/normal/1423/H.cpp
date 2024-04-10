#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define x first
#define y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct query {
    char type;
    int u, v;

    query() {};
    query(char _t, int _u, int _v) {
        type = _t;
        u = _u;
        v = _v;
    }
};

int born[1000009];
query ques[1000009];
int answ[1000009];

vector<pair<pii, int>> bydays[500009];

int sz[100009];
int par[100009];

vector<pii> change;

int get(int v) {
    while (par[v] != v) v = par[v];
    return v;
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);

    if (a == b) return;
    if (sz[a] < sz[b]) {
        change.push_back({b, sz[b]});
        change.push_back({-a - 1, a});
        par[a] = b;
        sz[b] += sz[a];
    }

    else {
        par[b] = a;
        change.push_back({a, sz[a]});
        sz[a] += sz[b];
        change.push_back({-b - 1, b});
    }
}

void gen(int l, int r) {
    if (r - l == 1) {
        if (ques[l].type == '?') {
            //cout << l << ' '<< ques[l].v << ' '<< get(ques[l].u) << ' ' << ques[l].u<< endl;
            answ[ques[l].v] = sz[get(ques[l].u)];
        }

        return;
    }

    int bck = change.size();
    int m = (r + l) / 2;
    for (int i = l; i < m; i++) {
        if (ques[i].type == '+' && born[i] >= r) {
            unite(ques[i].u, ques[i].v);
        }
    }

    gen(m, r);
    while (change.size() != bck) {
        auto p = change.back();
        if (p.x < 0) par[p.y] = p.y;
        else sz[p.x] = p.y;

        change.pop_back();
    }

    for (int i = m; i < r; i ++) {
        if (ques[i].type == '-' && born[i] < l) {
            unite(ques[i].u, ques[i].v);
        }
    }

    gen(l, m);
    while (change.size() != bck) {
        auto p = change.back();
        if (p.x < 0) par[p.y] = p.y;
        else sz[p.x] = p.y;

        change.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef karpovich
        freopen("input.txt", "r", stdin);
    #endif

    int n, q, k;
    cin >> n >> q >> k;

    for (int i = 0; i < n; i ++) {par[i] = i; sz[i] = 1;}

    int curr = 0, currd = 1, temp = 0;
    for (int i = 0; i < q; i ++) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            ques[curr] = {'+', a, b};
            bydays[currd].push_back({{a, b}, curr});
            born[curr] = 20000000;

            curr++;
        }

        else if (t == 2) {
            int x;
            cin >> x;
            x--;

            ques[curr] = {'?', x, temp};
            temp++;
            curr++;
        }

        else {
            currd++;
            if (currd >= k) {
                for (auto p : bydays[currd - k]) {
                    born[curr] = p.y;
                    born[p.y] = curr;
                    ques[curr] = {'-', p.x.x, p.x.y};
                    curr++;
                }
            }
        }
    }



    gen(0, curr);
    for (int i = 0; i < temp; i ++) {
        cout << answ[i] << '\n';
    }

    return 0;
}