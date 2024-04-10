#include <bits/stdc++.h>

#define next lol
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> p(n), s(m);
    unordered_map <int, vector <int> > cnt;
    cnt.rehash(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        cnt[p[i]].pb(i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &s[i]);
    }
    vector <int> a(m, 0), b(n, 0);
    vector <bool> used(m);
    int res = 0;
    int ans = 0;
    for (int it = 0; it < 31; it++) {
        for (int i = 0; i < m; i++) {
            if (used[i]) continue;
            if (!cnt[s[i]].empty()) {
                res += it;
                ans++;
                used[i] = true;
                b[cnt[s[i]].back()] = i + 1;
                a[i] = it;
                cnt[s[i]].pop_back();
            }
        }
        for (int i = 0; i < m; i++) {
            s[i] = (s[i] >> 1) + (s[i] & 1);
        }
    }
    printf("%d %d\n", ans, res);
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    puts("");
}