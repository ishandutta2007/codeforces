#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 1005;

int cnt[N];

int mex() {
    for (int i = 0; i <= 1000; i++) if (cnt[i] == 0) return i;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> res;

    while (true) {
        int me = mex();
        if (me != n) {
            cnt[a[me]]--;
            a[me] = me;
            res.pb(me);
            cnt[me]++;
        } else {
            int fir = -1;
            for (int i = 0; i < n; i++) if (a[i] != i) {
                fir = i;
                break;
            }
            if (fir == -1) break;
            int find = 0;
            for (int i = 0; i < n; i++) if (a[i] == fir) find = i;
            res.pb(find);
            res.pb(fir);
            cnt[a[fir]]--;
            a[fir] = fir;
            cnt[n]++;
            a[find] = n;
        }
    }

    cout << res.size() << '\n';
    for (int e : res) cout << e + 1 << ' ';
    cout << '\n';

    for (int i = 0; i <= 1000; i++) cnt[i] = 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}