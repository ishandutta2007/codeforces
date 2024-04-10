#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;
typedef vector<ll> vl;

const int K = 10; // 5
const int KF = 125; // 120
const int SS = 170; // 156

bool compare_bitset(const std::bitset<KF>& x, const std::bitset<KF>& y) {
    for (int i = KF - 1; i >= 0; i--) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}

int n, k;

vector<vi> perm;

int go[KF][KF];
int comb[SS][SS];
int sgo[SS][KF];
int sz[SS];
int id[KF];

map<bitset<KF>, int, decltype(compare_bitset)*> subgroups_set(compare_bitset);
vector<bitset<KF>> subgroups;

int get_pos(vi p) {
    return lower_bound(all(perm), p) - perm.begin();
}

vi apply(vi cur, vi p) { // permutation p gets applied to cur
    vi res(k);
    f0r(i, k) {
        res[p[i]] = cur[i];
    }
    return res;
}

bitset<KF> find_next_subgroup(bitset<KF> subgroup, int p) {
    bitset<KF> new_subgroup;
    vi use;
    f0r(i, sz(perm)) {
        if (subgroup[i]) {
            use.pb(i);
        }
    }

    use.pb(p);

    bitset<KF> vis;

    list<int> que;

    trav(t, use) {
        que.pb(t);
        vis[t] = 1;
    }

    while (!que.empty()) {
        auto cur = que.front();
        que.pop_front();

        trav(t, use) {
            if (!vis[go[cur][t]]) {
                que.pb(go[cur][t]);
                vis[go[cur][t]] = 1;
            }
        }
    }
    return vis;
}

int factorial(int x) {
    int res = 1;
    f1r(i, 1, x+1) res *= i;
    return res;
}

void bprint(bitset<KF> b) {
    f0r(i, sz(perm)) cout << b[i];
    cout << endl;
}

void gen() {
    vi use(k);
    iota(all(use), 0);
    do {
        perm.pb(use);
    } while (next_permutation(all(use)));

    sort(all(perm));

    f0r(i, sz(perm)) {
        f0r(j, sz(perm)) {
            go[i][j] = get_pos(apply(perm[i], perm[j]));
        }
    }

    bitset<KF> initial_subgroup;
    initial_subgroup[0] = 1;

    list<bitset<KF>> que;
    que.pb(initial_subgroup);
    subgroups_set[initial_subgroup] = sz(subgroups_set);

    while (!que.empty()) {
        auto cur = que.front();
        que.pop_front();

        f0r(i, sz(perm)) {
            auto nxt = find_next_subgroup(cur, i);
            if (subgroups_set.find(nxt) == subgroups_set.end()) {

                que.pb(nxt);

                sgo[subgroups_set[cur]][i] = sz(subgroups_set);
                subgroups_set[nxt] = sz(subgroups_set);
            } else {
                sgo[subgroups_set[cur]][i] = subgroups_set[nxt];
            }
        }
    }

    subgroups.resize(sz(subgroups_set));
    trav(t, subgroups_set) {
        subgroups[t.s] = t.f;
    }
    f0r(i, sz(subgroups)) {
        f0r(j, sz(subgroups)) {
            int cur = i;
            f0r(l, sz(perm)) {
                if (subgroups[j][l]) {
                    cur = sgo[cur][l];
                }
            }
            comb[i][j] = cur;
        }
    }

    f0r(i, sz(perm)) {
        bitset<KF> b;
        vi cur = perm[i];
        do {
            b[get_pos(cur)] = 1;
            cur = apply(cur, perm[i]);
        } while (cur != perm[i]);
        id[i] = subgroups_set[b];
    }

    f0r(i, sz(subgroups)) {
        sz[i] = subgroups[i].count();
    }
}

template <class T> struct SparseTable {
    std::vector<T> v;
    std::vector<std::vector<int>> jump;

    int level(int x) { return 31 - __builtin_clz(x); }

    int cmb(int a, int b) {
        return comb[a][b];
    }

    void init(const std::vector<T>& _v) {
        v = _v;
        jump = {std::vector<int>((int) v.size())};
        jump[0] = v;
        for (int j = 1; (1 << j) <= (int) v.size(); j++) {
            jump.push_back(std::vector<int>((int) v.size() - (1 << j) + 1));
            for (int i = 0; i < (int) jump[j].size(); i++) {
                jump[j][i] = cmb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int l, int r) {
        assert(l <= r);
        int d = level(r - l + 1);
        return sz[cmb(jump[d][l], jump[d][r - (1 << d) + 1])];
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    gen();

    // trav(t, subgroups) bprint(t);

    vi a(n);
    f0r(i, n) {
        vi use(k);
        f0r(j, k) cin >> use[j], use[j]--;
        a[i] = id[get_pos(use)];
    }

    SparseTable<int> S;
    S.init(a);
    vi s(n);
    f0r(i, n) s[i] = sz[a[i]];

    // f0r(i, n) cout << s[i] << " ";
    // cout << endl;

    // ll test = 0;
    // f0r(l, n) {
    //     f1r(r, l, n) { 
    //         test += S.query(l, r);
    //     }
    // }
    // cout << test << " TEST" << endl;

    vi ptr(sz(perm) + 1, -1); // last place >= i

    ll ans = 0;

    f0r(i, n) {
        int loc = i;
        while (loc >= 0) { // should be at most log2(120)
            int lo = 0;
            int hi = loc;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (S.query(mid, i) != S.query(loc, i)) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            int nloc;
            if (S.query(lo, i) == S.query(loc, i)) nloc = lo;
            else nloc = hi;
            ans += 1LL * (loc - nloc + 1) * S.query(loc, i);
            loc = --nloc;
        }
    }

    cout << ans << '\n';

    return 0;
}