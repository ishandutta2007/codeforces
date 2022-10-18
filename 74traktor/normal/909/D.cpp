#include<bits/stdc++.h>

using namespace std;

int const maxc = 1e6 + 5;
int nxt[maxc], lst[maxc], used[maxc];

inline void update(int x) {
    if (lst[x] >= 0) nxt[lst[x]] = nxt[x];
    lst[nxt[x]] = lst[x];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    set < int > oks;
    for (int i = 0; i < (int)s.size(); ++i) {
        nxt[i] = i + 1, lst[i] = i - 1;
        if (i > 0 && s[i] != s[i - 1]) oks.insert(i);
        if (i + 1 < (int)s.size() && s[i] != s[i + 1]) oks.insert(i);
    }
    while ((int)oks.size() > 0) {
        ans++;
        set < int > may_be;
        for (auto key : oks) {
            used[key] = 1;
            may_be.insert(lst[key]);
            may_be.insert(nxt[key]);
        }
        for (auto key : oks) {
            update(key);
        }
        oks = {};
        for (auto key : may_be) {
            if (key >= 0 && key < (int)s.size() && used[key] == 0) {
                if (lst[key] >= 0 && s[lst[key]] != s[key]) oks.insert(key);
                if (nxt[key] < (int)s.size() && s[nxt[key]] != s[key]) oks.insert(key);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}