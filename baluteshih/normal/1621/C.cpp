#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int ans[10005], n, cnt;

int query(int x) {
    ++cnt;
    assert(cnt <= 2 * n);
    cout << "? " << x << endl;
    int rt;
    cin >> rt;
    return rt;
}

void report() {
    cout << "!";
    for (int i = 1; i <= n; ++i)
        cout << " " << ans[i];
    cout << endl;
}

void init() {
    cin >> n, cnt = 0;
    for (int i = 1; i <= n; ++i)
        ans[i] = 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        init();
        for (int i = 1; i <= n; ++i)
            if (!ans[i]) {
                int lst = 0;
                while (lst != i)
                    lst = query(i);
                for (int nxt = query(i); nxt != i; lst = nxt, nxt = query(i))
                    ans[lst] = nxt;
                ans[lst] = i;
            }
        report();
    }
}