#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x),end(x)
#define fpos alflalfa

const int maxn = 2e5 + 42;

string s;
int link[maxn], len[maxn], fpos[maxn];
map<char, int> to[maxn];
int sz = 1, last;

void add_letter(char c) {
    int p = last;
    last = sz++;
    len[last] = fpos[last] = len[p] + 1;
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
    fpos[cl] = fpos[q];
    link[cl] = link[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for(; to[p][c] == q; p = link[p]) {
        to[p][c] = cl;
    }
}

vector<int> g[maxn];
int in[maxn], out[maxn];
map<char, int> rto[maxn];
int t;

void dfs(int v = 0) {
    in[v] = t++;
    for(auto u: g[v]) {
        rto[v][s[fpos[u] - len[v] - 1]] = u;
    }
    for(auto it: rto[v]) {
        dfs(it.second);
    }
    out[v] = t;
}

int mx[4 * maxn];

void upd(int p, int c, int v = 1, int l = 0, int r = maxn) {
    mx[v] = c;
    if(r - l > 1) {
        int m = (l + r) / 2;
        if(p < m) {
            upd(p, c, 2 * v, l, m);
        } else {
            upd(p, c, 2 * v + 1, m, r);
        }
    }
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return mx[v];
    } else if(r <= a || b <= l) {
        return 0;
    } else {
        int m = (l + r) / 2;
        return max(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
    }
}

int used[maxn];
int n, m;


string get_str() {
    string s;
    for(int i = 0; i < 10; i++) {
        s += 'a' + (rand() % 2);
    }
    cin >> s;
    n = s.size();
    return s;
}

int get_m() {
    int m = 100;
    cin >> m;
    return m;
}

void get(int &l, int &r, string &t) {
    l = rand() % n + 1;
    r = rand() % n + 1;
    if(l > r) {
        swap(l, r);
    }
    for(int i = 0; i < 4; i++) {
        t += 'a' + (rand() % 2);
    }
    cin >> l >> r >> t;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int seed = 1535904772;//time(NULL);
    srand(seed);
    s = get_str();//cin >> s;
    n = s.size();
    reverse(begin(s), end(s));
    for(auto c: s) {
        add_letter(c);
    }
    for(int i = 1; i < sz; i++) {
        g[link[i]].push_back(i);
    }
    dfs();
    m = get_m();//cin >> m;
    vector<int> l(m), r(m);
    string ans[m];
    string qq[m];
    vector<int> que[n];
    for(int i = 0; i < m; i++) {
        get(l[i], r[i], qq[i]);//cin >> l[i] >> r[i] >> qq[i];
        que[l[i] - 1].push_back(i);
    }
    int v = 0;
    for(int i = 1; i <= n; i++) {
        v = to[v][s[i - 1]];
        upd(in[v], i);


        for(auto it: que[n - i]) {
            int go_to = 0;
            int ln = 0;
            int best_ln = 0;
            int best_v = 0;
            auto ok = [&](int v, int ln) {
                int first_l = n - get(in[v], out[v]);
                return first_l + ln <= r[it];
            };
            qq[it] += "#";
            for(auto c: qq[it]) {
                ln++;
                if(ln == len[go_to] + 1) {
                    for(auto it: rto[go_to]) {
                        char nc = it.first;
                        int n_goto = it.second;
                        if(nc > c && ok(n_goto, ln)) {
                            best_ln = ln;
                            best_v = n_goto;
                            break;
                        }
                    }
                    if(!rto[go_to].count(c)) {
                        break;
                    } else {
                        go_to = rto[go_to][c];
                    }

                } else {
                    char true_c = s[fpos[go_to] - ln];
                    if(true_c == c) {
                        if(ok(go_to, ln)) {
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        if(true_c > c && ok(go_to, ln)) {
                            best_ln = ln;
                            best_v = go_to;
                        }
                        break;
                    }
                }
            }



            if(best_ln == 0) {
                ans[it] = "1-";
            } else {
                ans[it] = s.substr(fpos[best_v] - best_ln, best_ln);
            }
        }
    }
    for(auto it: ans) {
        reverse(all(it));
        cout << it << "\n";
    }
    return 0;
}