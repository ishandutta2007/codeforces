#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;

struct Event {
    int type;
    int t;
    int l, r, id, h;
};

int h, w, n;
vector<int> e[N];
ll dp[N];
set<pair<int,int>> tree[N * 4];
int bestH, bestId;

void ask(int v, int tl, int tr, int pos) {
    if (!tree[v].empty()) {
        auto x = *tree[v].rbegin();
        if (bestH < x.F) {
            bestH = x.F;
            bestId = x.S;
        }
    }

    if (tl + 1 == tr) {
        return;
    }
    if (pos < (tl + tr) / 2)
        ask(v * 2 + 1, tl, (tl + tr) / 2, pos);
    else
        ask(v * 2 + 2, (tl + tr) / 2, tr, pos);
}

void add(int v, int tl, int tr, int l, int r, pair<int,int> val) {
    if (r <= tl || tr <= l) return;
    if (l <= tl && tr <= r) {
        assert(tree[v].insert(val).S);
        return;
    }
    add(v * 2 + 1, tl, (tl + tr) / 2, l, r, val);
    add(v * 2 + 2, (tl + tr) / 2, tr, l, r, val);
}

void rem(int v, int tl, int tr, int l, int r, pair<int,int> val) {
    if (r <= tl || tr <= l) return;
    if (l <= tl && tr <= r) {
        assert(tree[v].erase(val));
        return;
    }
    rem(v * 2 + 1, tl, (tl + tr) / 2, l, r, val);
    rem(v * 2 + 2, (tl + tr) / 2, tr, l, r, val);
}




int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    ll answer = 0;
    scanf("%d%d%d", &h, &w, &n);
    vector<Event> event;
    for (int i = 0; i < w; i++) {
        event.pb({0, h + 1, i, i + 1, -1, -1});
    }
    vector<pair<int,int>> ord;
    for (int i = 0; i < n; i++) {
        int u, l, r, s; 
        scanf("%d%d%d%d", &u, &l, &r, &s); l--;
        ord.pb(mp(u, i));
        event.pb({1, u, l, r, i, u});
        event.pb({2, u + s, l, r, i, u});
        int p1 = l - 1;
        int p2 = r;
        if (p1 == -1) {
            p1 = p2;
        }
        if (p2 == w)
            p2 = p1;
        assert(0 <= p1 && p1 < w);
        assert(0 <= p2 && p2 < w);
        event.pb({0, u, p1, p1 + 1, i, -1});
        event.pb({0, u, p2, p2 + 1, i, -1});
    }

    sort(all(event), [](Event A, Event B) {
            return A.t < B.t || (A.t == B.t && A.type < B.type);
            });
    for (auto x: event) {
        if (x.type == 1) {
            add(0, 0, w, x.l, x.r, mp(x.h, x.id));
        }
        if (x.type == 2) {
            rem(0, 0, w, x.l, x.r, mp(x.h, x.id));
        }
        if (x.type == 0) {
            bestH = -1;
            bestId = -1;
            ask(0, 0, w, x.l);
            if (x.id == -1) {
                if (bestId == -1) {
                    answer++;
                }
                else {
                    dp[bestId]++;
                }
            }
            else {
                e[x.id].pb(bestId);
            }
        }
    }

    sort(all(ord));
    reverse(all(ord));
    for (auto x: ord) {
        int id = x.S;
        for (auto u: e[id]) {
            if (u == -1)
                answer = (answer + dp[id]) % MOD;
            else {
                dp[u] = (dp[u] + dp[id]) % MOD;
            }
        }
    }

    cout << answer % MOD << endl;
    return 0;
}