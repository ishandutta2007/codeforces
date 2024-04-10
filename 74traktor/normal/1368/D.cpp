/*
,  ?  ?
 Cadillac
 ,  
 , ,   (, few)
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

multiset < int > Q;
int cnt[(1 << 20)];
unordered_set < int > go[20];

inline void add(int x) {
    cnt[x]++;
    Q.insert(x);
    if (cnt[x] > 1) return;
    for (int j = 0; j <= 19; ++j) {
        if ((x&(1 << j)) > 0) go[j].insert(x);
    }
}

inline void del(int x) {
    cnt[x]--;
    Q.erase(Q.find(x));
    if (cnt[x] > 0) return;
    for (int j = 0; j <= 19; ++j) {
        if ((x&(1 << j)) > 0) go[j].erase(x);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        add(x);
    }
    while ((int)Q.size() > 0) {
        x = (*Q.rbegin());
        del(x);
        for (int j = 19; j >= 0; --j) {
            if ((x&(1 << j)) == 0) {
                if ((int)go[j].size() > 0) {
                    int y = (*go[j].begin());
                    del(y);
                    add((x&y));
                    x = (x|y);
                }
            }
        }
        ans += (ll)x * (ll)x;
    }
    cout << ans << '\n';
    return 0;
}