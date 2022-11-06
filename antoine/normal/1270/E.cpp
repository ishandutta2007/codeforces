#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    for(;;) {
        vector<int> v;
        for(int i  = 0; i < n; ++i)
            if((x[i] + y[i])%2)
                v.push_back(i);
        if(!v.empty() && v.size() < n) {
            cout << v.size() << '\n';
            for(int i : v)
                cout << i + 1 << ' ';
            return 0;
        }

        if((x[0] + y[0]) %2) {
            for(ll &xx : x)
                xx++;
        }
        for(int i = 0; i < n;++i) {
            int u = (x[i] - y[i]) / 2;
            int v = (x[i] + y[i]) / 2;
            x[i] = u;
            y[i] = v;
        }
    }
    return 0;
}