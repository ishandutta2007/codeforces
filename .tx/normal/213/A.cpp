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

int c[222];
vector<int> g[222];
int d[222];
int od[222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(c[i]);
        --c[i];
    }
    for (int i = 0; i < n; i++) {
        scid(k);
        for (int j = 0; j < k; j++) {
            scid(x);
            --x;
            g[x].push_back(i);
        }
        d[i] = od[i] = k;
    }

    int gans = 1e9;

    for (int st = 0; st < 3; st++) {

        int cur = st;
        int ans = -1;
        int done = 0;
        memcpy(d, od, sizeof(d));
        while (done < n) {
            ans++;
            bool changed = true;
            while (changed) {
                changed = false;
                for (int i = 0; i < n; i++) {
                    if (c[i] == cur && d[i] == 0) {
                        done++;
                        ans++;
                        for (int j : g[i]) {
                            d[j]--;
                        }
                        d[i] = -1;
                        changed = true;
                    }
                }
            }
            cur++;
            if (cur == 3) {
                cur = 0;
            }
        }
        gans = min(gans, ans);
    }

    cout << gans;

    return 0;
}