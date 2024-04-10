#include <bits/stdc++.h>

using namespace std;

#define int long long

int lst(int x) {
    return x % 10;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;
        int ans = 0, cnt = n / m;
        vector < int > go;
        int x = m, sum = 0;
        sum = lst(m);
        go.push_back(lst(m));
        while (1) {
            x += m;
            int h = lst(x);
            bool check = false;
            for (auto key : go) {
                if (key == h) check = true;
            }
            if (check) break;
            sum += h;
            go.push_back(h);
        }
        ans = cnt / (int)go.size() * sum;
        for (int j = 0; j < cnt % (int)go.size(); ++j) ans += go[j];
        cout << ans << '\n';
    }
    return 0;
}