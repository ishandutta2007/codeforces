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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

lint M1 = 1e9 + 7;
lint M2 = 1e9 + 9;
lint p1 = 31;
lint p2 = 239;

int d[2222222];
int p[2222222];
lint hs1[2222222];
lint hs2[2222222];
lint ps1[2222222];
lint ps2[2222222];

int last[111111];
int tt[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, k);
    scids(s);
    s += s;
    scid(m);

    map<pair<lint, lint>, int> gs;

    for (int i = 0; i < m; i++) {
        scids(g);
        lint h1 = 0;
        lint h2 = 0;
        for (int j = 0; j < k; j++) {
            h1 = (h1 * p1 + g[j] - 'a' + 1) % M1;
            h2 = (h2 * p2 + g[j] - 'a' + 1) % M2;
        }
        gs[{h1, h2}] = i;
    }

    lint h1 = 0;
    lint h2 = 0;
    for (int i = 0; i < s.size(); i++) {
        h1 = (h1 * p1 + s[i] - 'a' + 1) % M1;
        h2 = (h2 * p2 + s[i] - 'a' + 1) % M2;
        hs1[i] = h1;
        hs2[i] = h2;
    }


    lint p1k = 1;
    lint p2k = 1;
    for (int i = 0; i < s.size() + 1; i++) {
        ps1[i] = p1k;
        ps2[i] = p2k;
        p1k = p1k * p1 % M1;
        p2k = p2k * p2 % M2;
    }

    int tm = 0;

    int len = s.size();

    for (int md = 0; md < k; md++) {
        ++tm;
        fill(d, d + 2 * n + 1, 0);
        int ii = 1;
        for (int i = md; i < len; i += k, ii++) {
            h1 = ((hs1[i] - (i == md ? 0 : hs1[i - k] * ps1[k])) % M1 + M1) % M1;
            h2 = ((hs2[i] - (i == md ? 0 : hs2[i - k] * ps2[k])) % M2 + M2) % M2;

            auto it = gs.find({h1, h2});
            if (it != gs.end()) {
                d[ii] = d[ii - 1] + 1;
                int x = it->second;
                p[ii] = x;
                if (tt[x] == tm) {
                    d[ii] = min(d[ii], ii - last[x]);
                }
                tt[x] = tm;
                last[x] = ii;
            }
        }

        for (int i = 1; i < ii; i++) {
            if (d[i] == n) {
                cout << "YES\n";
                int x = i;
                vector<int> ans;
                for (int j = 0; j < n; j++) {
                    ans.push_back(p[x]);
                    x--;
                }
                reverse(ans.begin(), ans.end());
                for (int i : ans) {
                    cout << i + 1 << " ";
                }
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}