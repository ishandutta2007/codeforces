#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long

const int MAXN = (int) 5e5 + 7;
const int MAXV = 2 * MAXN;

map <char, int> to[MAXV];
vector <int> guys[MAXN];
int len[MAXV], link[MAXV];
ll cnt[MAXV];
int sz = 1, last;

void init() {
    link[0] = -1;
    len[0] = 0;
}

void add_char(char c) {
    if (to[last].count(c) && len[to[last][c]] == len[last] + 1) {
        last = to[last][c];
        return;
    }
    int cur = sz++;
    int p = last;
    len[cur] = len[p] + 1;
    while (p != -1 && !to[p].count(c)) {
        to[p][c] = cur;
        p = link[p];
    }
    if (p == -1) {
        link[cur] = 0;
    } else {
        int q = to[p][c];
        if (len[q] == len[p] + 1) {
            link[cur] = q;
        } else {
            int suf = sz++;
            link[suf] = link[q];
            to[suf] = to[q];
            len[suf] = len[p] + 1;
            while (p != -1 && to[p][c] == q) {
                to[p][c] = suf;
                p = link[p];
            }
            link[cur] = link[q] = suf;
        }
    }
    last = cur;
}



int main() {
    ios_base::sync_with_stdio(0);
    init();
    int n;
    int mx = 0;
    cin >> n;
    vector <string> t(n);
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        for (char f : t[i]) {
            add_char(f);
            cnt[last] += c[i];
        }
        last = 0;
    }
    for (int i = 1; i < sz; i++) {
        guys[len[i]].pb(i);
        mx = max(mx, len[i]);
    }
    ll ans = 0;
    for (int go = mx; go >= 0; go--) {
        for (auto p : guys[go]) {
            cnt[link[p]] += cnt[p];
            ans = max(ans, len[p] * (ll) cnt[p]);
        }
    }
    cout << ans << endl;
}