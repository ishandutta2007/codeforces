#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    for(int &x: b)cin >> x;
    const vector<int> a = b;
    ll sum = accumulate(b.begin(), b.end(), 0LL);
    if(sum < n) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < m - 1; ++i) {
        int &x=  b[i];
        int d = (int)min(sum - n, x - 1LL);
        x -= d;
        sum -= d;
    }

    if(sum != n) {
        cout << -1;
        return 0;
    }

    vector<int> pos(m, 1);
    for(int i = 1; i < m; ++i)
        pos[i] = pos[i-1] + b[i-1];
    for(int i = 0; i < m; ++i)
        if(pos[i] + a[i] > n + 1) {
            cout << -1;
            return 0;
        }
    for(int x : pos)
        cout << x << ' ';

    return 0;
}