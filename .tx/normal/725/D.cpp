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

pair<lint, lint> a[333333];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    --n;
    scidl(ot, ow);

    for (int i = 0; i < n; i++) {
        sci(a[i].first, a[i].second);
        a[i].first *= -1;
    }
    sort(a, a + n);
    int cp = 0;
    priority_queue<pair<lint, int> > q;
    for (int i = 0; i < n; i++) {
        if (-a[i].first > ot) {
            cp++;
            q.push({-(a[i].second + a[i].first), i});
        }
    }

    int ci = cp;
    int ans = cp;

    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        lint nd = -v.first + 1;
        if (ot < nd) {
            break;
        }
        ot -= nd;
        cp--;
        while (ci < n && -a[ci].first > ot) {
            q.push({-(a[ci].second + a[ci].first), ci});
            ci++;
            cp++;
        }
        ans = min(ans, cp);
    }

    cout << ans + 1;


    return 0;
}