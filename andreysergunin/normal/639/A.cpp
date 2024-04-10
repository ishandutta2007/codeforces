#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<int> v;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int id;
            cin >> id;
            --id;
            if (sz(v) < k) {
                v.pb(id);
            } else {
                int idmin = 0;
                for (int i = 0; i < k; ++i) {
                    if (t[v[i]] < t[v[idmin]]) {
                        idmin = i;
                    }
                }
                if (t[v[idmin]] > t[id]) {
                    continue;
                } else {
                    v[idmin] = id;
                }
            }
        } else {
            int id;
            cin >> id;
            --id;
            bool ok = false;
            for (int i = 0; i < sz(v); ++i) {
                if (v[i] == id) {
                    ok = true;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }

}