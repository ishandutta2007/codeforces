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
typedef int my_int;

#define int long long


int mabs(int x) {
    return x < 0 ? -x : x;
}

my_int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    scid(n, k, x);
    priority_queue<pair<int, pair<int, int>>> q;
    int kneg = 0;
    int kzero = 0;
    for (int i = 0; i < n; i++) {
        scid(y);
        if (y < 0) {
            kneg++;
        }
        if (y == 0) {
            kzero++;
        }
        q.push({-mabs(y), {y, i}});
    }

    while (k-- > 0) {//
        auto v = q.top().second;
        int y = v.first;
        int id = v.second;
        q.pop();
        if (y == 0) {
            if (kzero == 1 && kneg % 2 == 0) {
                y -= x;
            } else {
                y += x;
            }
            kzero--;
        } else {
            if (y < 0) {
                if (kneg % 2 == 1) {
                    y -= x;
                } else {
                    y += x;
                }
                kneg--;
            } else {
                if (kneg % 2 == 1) {
                    y += x;
                } else {
                    y -= x;
                }
            }
        }
        q.push({-mabs(y), {y, id}});
        if (y < 0) {
            kneg++;
        }
        if (y == 0) {
            kzero++;
        }
    }

    vector<int> ans(n);
    while (!q.empty()) {
        auto v = q.top().second;
        q.pop();
        ans[v.second] = v.first;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}