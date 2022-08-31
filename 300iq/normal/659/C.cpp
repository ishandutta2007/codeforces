#include <bits/stdc++.h>
#define int long long

using namespace std;

vector <int> a;

main() {
    int n, m, x;
    cin >> n >> m;
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (a.back() != 1000000000) {
        a.push_back(1000000000);
    }
    int ans = 0;
    vector <int> res;
    for (int i = 1; i < (int) a.size(); i++) {
        int p = a[i - 1] + 1;
        while (p < a[i] && ans + p <= m) {
            ans += p;
            res.push_back(p);
            p++;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < (int) res.size(); i++) {
        cout << res[i] << " ";
    }
}