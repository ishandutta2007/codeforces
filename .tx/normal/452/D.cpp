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

int iw[3];
int aw[3];
int ns[3];
int ts[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sci(aw[0]);
    for (int i = 0; i < 3; i++) {
        sci(ns[i]);
    }
    for (int i = 0; i < 3; i++) {
        sci(ts[i]);
    }

    priority_queue<pair<int, int> > q;

    int ans = 0;
    int tt = min(ns[0], aw[0]);
    for (int i = 0; i < tt; i++) {
        q.push({-ts[0], 0});
        aw[0]--;
        ns[0]--;
    }

    while (!q.empty()) {
        int tm = -q.top().first;
        int tp = q.top().second;
        q.pop();

        if (tp == 0) {
            ns[0]++;
            if (ns[1] > 0) {
                q.push({-tm - ts[1], 1});
                ns[1]--;
            } else {
                aw[1]++;
            }
            if (aw[0] > 0) {
                q.push({-tm - ts[0], 0});
                ns[0]--;
                aw[0]--;
            }
        } else if (tp == 1) {
            ns[1]++;
            if (ns[2] > 0) {
                q.push({-tm - ts[2], 2});
                ns[2]--;
            } else {
                aw[2]++;
            }
            if (aw[1] > 0) {
                q.push({-tm -ts[1], 1});
                ns[1]--;
                aw[1]--;
            }
        } else {
            ans = max(ans, tm);
            ns[2]++;
            if (aw[2] > 0) {
                q.push({-tm - ts[2], 2});
                ns[2]--;
                aw[2]--;
            }
        }
    }

    cout << ans;

    return 0;
}