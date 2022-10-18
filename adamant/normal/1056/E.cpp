#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 2e6 + 42;

#define link laaflak

int inv[maxn], len[maxn];

struct automaton {
    int link[maxn];
    map<char, int> to[maxn];
    int last, sz = 1;

    void add_letter(char c) {
        int p = last;
        last = sz++;
        len[last] = len[p] + 1;
        inv[len[last]] = last;
        for(; to[p][c] == 0; p = link[p]) {
            to[p][c] = last;
        }
        if(to[p][c] == last) {
            return;
        }
        int q = to[p][c];
        if(len[q] == len[p] + 1) {
            link[last] = q;
            return;
        }
        int cl = sz++;
        to[cl] = to[q];
        link[cl] = link[q];
        len[cl] = len[p] + 1;
        link[last] = link[q] = cl;
        for(; to[p][c] == q; p = link[p]) {
            to[p][c] = cl;
        }
    }
};

int qln[maxn], qans[maxn];
vector<int> que[maxn];
int qsz = 0;

bool eq(int v1, int v2, int ln, int mod = 0) {
    if(mod == 0) {
        que[v1].push_back(qsz);
        que[v2].push_back(qsz);
        qln[qsz++] = ln;
    } else {
        return qans[qsz++];
    }
}

vector<int> g[maxn];

vector<pair<int, int>> st;

void dfs(int v = 0) {
    st.push_back({len[v], v});
    for(auto u: g[v]) {
        dfs(u);
    }
    for(auto it: que[v]) {
        auto jt = lower_bound(all(st), make_pair(qln[it], 0));
        assert(jt != end(st));
        int u = jt->second;
        if(qans[it] == -1) {
            qans[it] = u;
        } else {
            qans[it] = qans[it] == u;
        }
    }
    st.pop_back();
}

void build_automaton(string t) {
    automaton me;
    for(auto c: t) {
        me.add_letter(c);
    }
    for(int i = 1; i < me.sz; i++) {
        g[me.link[i]].push_back(i);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(qans, -1, sizeof(qans));
    string s, t;
    cin >> s >> t;
    build_automaton(t);
    
    int n = t.size();
    int cnt0 = count(all(s), '0');
    int cnt1 = count(all(s), '1');
    for(int len0 = 1; len0 * cnt0 < n; len0++) {
        int len1 = n - len0 * cnt0;
        if(len1 % cnt1 == 0) {
            len1 /= cnt1;
            int type0 = -1;
            int type1 = -1;
            int cur = 0;
            bool ok = true;
            for(auto c: s) {
                if(c == '0') {
                    cur += len0;
                    if(type0 == -1) {
                        type0 = cur;
                    } else {
                        ok &= eq(inv[type0], inv[cur], len0);
                    }
                } else {
                    cur += len1;
                    if(type1 == -1) {
                        type1 = cur;
                    } else {
                        ok &= eq(inv[type1], inv[cur], len1);
                    }
                }
            }
            ok &= len0 != len1 || !eq(inv[type0], inv[type1], len0);
            //ans += ok;
        }
    }
    dfs();
    qsz = 0;
    int ans = 0;
    for(int len0 = 1; len0 * cnt0 < n; len0++) {
        int len1 = n - len0 * cnt0;
        if(len1 % cnt1 == 0) {
            len1 /= cnt1;
            int type0 = -1;
            int type1 = -1;
            int cur = 0;
            bool ok = true;
            for(auto c: s) {
                if(c == '0') {
                    cur += len0;
                    if(type0 == -1) {
                        type0 = cur;
                    } else {
                        ok &= eq(inv[type0], inv[cur], len0, 1);
                    }
                } else {
                    cur += len1;
                    if(type1 == -1) {
                        type1 = cur;
                    } else {
                        ok &= eq(inv[type1], inv[cur], len1, 1);
                    }
                }
            }
            ok &= len0 != len1 || !eq(inv[type0], inv[type1], len0, 1);
            ans += ok;
        }
    }
    
    cout << ans << endl;
    return 0;
}