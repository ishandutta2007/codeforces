#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <multiset <int>> a(n);
    int s = 0;
    forn (i, 0, m) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        a[t1].insert(t2);
        s++;
    }
    vector <int> ans(n);
    forn (i, 0, n) {
        int j = i, cnt = 0;
        vector <multiset <int>> c = a;
        multiset <int> b;
        int anss = 0;
        while (cnt < s) {
            if (c[j].size()) {
                /*if (c[j].upper_bound(j) == c[j].end()) {
                    b.insert(*c[j].begin());
                    c[j].erase(c[j].find(*c[j].begin()));
                } else {
                    b.insert(*c[j].upper_bound(j));
                    c[j].erase(c[j].find(*c[j].upper_bound(j)));
                }*/
                if (c[j].lower_bound(j) != c[j].begin()) {
                    b.insert(*--c[j].lower_bound(j));
                    c[j].erase(c[j].find(*--c[j].lower_bound(j)));
                } else {
                    b.insert(*--c[j].end());
                    c[j].erase(c[j].find(*--c[j].end()));
                }
            }
            cnt += b.count(j);
            if (b.count(j))
                b.erase(j);
            /*cout << j << ": ";
            for (auto k : b)
                cout << k <<  " ";
            cout << "\n";*/
            j =  (j + 1) % n;
            anss++;
        }
        ans[i] = anss;
       // cout << "\n\n";
    }
    forn (i, 0, n)
        cout << ans[i] - 1 << " ";
    return 0;
}