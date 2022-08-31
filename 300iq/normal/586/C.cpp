#include <bits/stdc++.h>
#define int long long

using namespace std;

vector <int> v, d, p;
const int MAXN = 5000;
bool klick[MAXN];

main() {
    int n;
    cin >> n;
    v.resize(n), d.resize(n), p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> d[i] >> p[i];
    }
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (p[j] < 0 && !klick[j]) {
                for (int t = j + 1; t < n; t++) {
                    p[t] -= d[j];
                }
                klick[j] = 1;
            }
        }
        if (p[i] < 0) {
            continue;
        }
        ans.push_back(i + 1);
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (p[j] >= 0) {
                if (v[i] > 0) {
                    p[j] -= v[i];
                }
                v[i]--;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }
}