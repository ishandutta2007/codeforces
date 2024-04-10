#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[222222];
int t[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, w, k);
    int ans = 0;
    set<pair<int, int>> ws;
    set<pair<int, int>> rest;
    int ct = 0;
    int ca = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    for (int i = 0; i < n; i++) {
        sci(t[i]);
    }
    
    int lst = -1;
    
    for (int i = 0; i < n; i++) {
        rest.insert({t[i], i});
        ca += a[i];
        ct += t[i];
        if (ws.size() == w) {
            auto it = ws.begin();
            ct += it->first / 2;
            rest.insert(*it);
            ws.erase(it);
        }
        auto it = rest.rbegin();
        ct -= it->first / 2;
        ws.insert(*it);
        rest.erase(*it);
        while (ct > k) {
            ++lst;
            auto p = make_pair(t[lst], lst);
            if (ws.find(p) != ws.end()) {
                ws.erase(p);
                ct -= (t[lst] + 1) / 2;
            } else {
                rest.erase(p);
                ct -= t[lst];
            }
            ca -= a[lst];
            if (ws.size() < w && !rest.empty()) {
                auto it = rest.rbegin();
                ct -= it->first / 2;
                ws.insert(*it);
                rest.erase(*it);
            }
        }
        ans = max(ans, ca);
    }
    
    cout << ans;
    

    return 0;
}