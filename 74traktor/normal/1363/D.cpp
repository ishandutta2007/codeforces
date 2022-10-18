#include<bits/stdc++.h>

using namespace std;

vector < int > a[1005];
int used[1005];

int ask(vector < int > d) {
    if ((int)d.size() == 0) return 0;
    cout << "? " << (int)d.size() << " ";
    for (auto key : d) cout << key << " ";
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, c, x;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) used[i] = 0;
        for (int i = 1; i <= k; ++i) {
            a[i] = {};
            cin >> c;
            for (int j = 1; j <= c; ++j) {
                cin >> x;
                used[x] = 1;
                a[i].push_back(x);
            }
        }
        vector < int > d1, d2;
        for (int i = 1; i <= n; ++i) {
            if (used[i] == 0) d1.push_back(i);
            else d2.push_back(i);
        }
        int mx = ask(d2);
        int lef = 1, righ = k;
        while (righ - lef >= 1) {
            int mid = (righ + lef) / 2;
            d2 = {};
            for (int i = lef; i <= mid; ++i) {
                for (auto key : a[i]) d2.push_back(key);
            }
            if (ask(d2) == mx) righ = mid;
            else lef = mid + 1;
        }
        assert(lef == righ);
        d2 = {};
        for (int i = 1; i <= n; ++i) {
            int ok = 1;
            for (auto key : a[lef]) if (key == i) ok = 0;
            if (ok) d2.push_back(i);
        }
        int f = ask(d2);
        cout << "! ";
        if (f >= mx) {
            for (int i = 1; i <= k; ++i) cout << f << " ";
        }
        else {
            for (int i = 1; i <= k; ++i) {
                if (lef == i) cout << f << " ";
                else cout << mx << " ";
            }
        }
        cout << endl;
        string s;
        cin >> s;
    }
    return 0;
}