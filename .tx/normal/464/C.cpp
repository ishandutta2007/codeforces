#include <bits/stdc++.h>

using namespace std;

template<typename T>
void sci(T &t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T &t, Ts &... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

const int MOD = 1e9 + 7;

lint plen[11];
lint pv[11];

vector<pair<int, string> > qs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    scids(s);
    for (int i = 0; i < 10; i++) {
        plen[i] = 10;
        pv[i] = i;
    }

    scid(q);
    for (int i = 0; i < q; i++) {
        scid(x);
        scids(t);
        t = t.substr(2, t.size() - 2);
        qs.push_back({x, t});
    }

    for (int qq = q - 1; qq >= 0; --qq) {
        auto cq = qs[qq].first;
        auto sq = qs[qq].second;

        lint nplen = 1;
        lint nv = 0;

        for (char c : sq) {
            int d = c - '0';
            nplen = nplen * plen[d] % MOD;
            nv = (nv * plen[d] + pv[d]) % MOD;
        }
        plen[cq] = nplen;
        pv[cq] = nv;
    }

    lint ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        ans = (ans * plen[d] + pv[d]) % MOD;
    }

    cout << ans;


    return 0;
}