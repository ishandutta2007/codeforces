#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

struct Query {
    int k, pos, id;
} q[N];

vector<ii> v;
int n, m, a[N], res[N], bit[N];

bool cmp(ii x, ii y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x > y.x;
}

bool cmp2(Query x, Query y) {
    return x.k < y.k;
}

struct OrderSet {
    #define bit(x, y) (x>>y)&1
    struct Trie {
        int cnt;
        int next[2];
        Trie() {
            next[0] = next[1] = -1;
            cnt = 0;
        }
    };
    
    vector<Trie> trie;
    
    OrderSet() {
        auto u = Trie();
        trie.pb(u);
    }

    bool find(int x) {
        int cur = 0;
        for (int i = 20; i >= 0; i--) {
            auto u = bit(x, i);
            if (trie[cur].next[u] == -1) return 0;
            else cur = trie[cur].next[u];
        }
        return 1;
    }

    void insert(int x) {
        int cur = 0;
        trie[cur].cnt++;
        for (int i = 20; i >= 0; i--) {
            auto u = bit(x, i);
            if (trie[cur].next[u] == -1) {
                auto newTrie = Trie();
                trie.pb(newTrie);
                trie[cur].next[u] = trie.size() - 1;
                cur = trie[cur].next[u];
            } else {
                cur = trie[cur].next[u];
            }
            trie[cur].cnt++;
        }
    }

    void deletee(int x) {
        int cur = 0;
        trie[cur].cnt--;
        for (int i = 20; i >= 0; i--) {
            auto u = bit(x, i);
            int temp = trie[cur].next[u];
            if (trie[temp].cnt == 1) trie[cur].next[u] = -1;
            cur = temp;
            trie[cur].cnt--;
        }
    }

    int order_of_key(int x) {
        int cur = 0;
        int res = 0;
        for (int i = 20; i >= 0; i--) {
            auto u = bit(x, i);
            if (u == 1 && trie[cur].next[0] != -1) {
                int temp = trie[cur].next[0];
                res += trie[temp].cnt;
            }
            if (trie[cur].next[u] == -1) return res;
            cur = trie[cur].next[u];
        }
        return res;
    }

    int find_by_order(int k) {
        int cur = 0;
        int res = 0;
        if (trie[cur].cnt < k) return -1;
        for (int i = 20; i >= 0; i--) {
            int temp = trie[cur].next[0];
            if (temp == -1) {
                cur = trie[cur].next[1];
                res += (1 << i);
                continue;
            }
            if (trie[temp].cnt < k) {
                k -= trie[temp].cnt;
                cur = trie[cur].next[1];
                res += (1 << i);
            } else {
                cur = trie[cur].next[0];
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    OrderSet *os = new OrderSet();
    cin >> n;
    v.pb({1e9 + 2, 1e9});
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.pb({a[i], i});
    }
    sort(all(v), cmp);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].k >> q[i].pos;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp2);
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        while (cur < q[i].k) {
            cur++;
            os->insert(v[cur].y);
        }
        res[q[i].id] = os->find_by_order(q[i].pos);
    }
    for (int i = 1; i <= m; i++) cout << a[res[i]] << '\n';
    return 0; 
}