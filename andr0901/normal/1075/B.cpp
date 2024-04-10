#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> v(n + m);
    forn (i, 0, n + m)
        cin >> v[i];
    /*vector <bool> u(n);
    vector <int> a;
    forn (i, 0, n) {
        cin >> u[i];
        if (u[i])
            a.push_back(v[i])
    }
    int st;
    forn (i, 0, n) {
        if (u[i])  {
            st = i;
            break;
        }
    }
    vector <int> ans(a.size());
    int j = 0;
    forn (i, st + 1, n) {
        if (v[i] - )
    }*/
    vector <int> a, b;
    forn (i, 0, n + m) {
        int t;
        cin >> t;
        if (t == 1)
            b.push_back(v[i]);
        else
            a.push_back(v[i]);
    }
    vector <int> ans(b.size());
    int st;
    forn (i, 0, a.size()) {
        st = i;
        if (a[i] > b[0]) {
            break;
        }
    }
    int fin;
    for (int i = a.size() - 1; i >= 0; i--) {
        fin = i;
        if (a[i] < b.back()) {
            break;
        }
    }
    b.push_back(2e9 + 10);
    int j = 0;
    //cout << st << " " << fin << " ";
    forn (i, st, fin + 1) {
        while (a[i] - b[j] > -a[i] + b[j + 1])
            j++;
        ans[j]++;
    }
    ans[0] += st;
    ans[ans.size() - 1] += (a.size() - fin - 1);
    forn (i, 0, ans.size())
        cout << ans[i] << " ";
    return 0;
}