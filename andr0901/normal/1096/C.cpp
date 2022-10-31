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
    int t;
    cin >> t;
    vector <int> ans(181);
    forn (i, 3, 1000) {
        //double a = 180 / i;
        forn (j, 1, i - 1)
            if ((180 * j) % i == 0)
                if (!ans[180 * j / i])
                    ans[180 * j / i] = i;
    }
    //forn (i, 1, 181)
    //    cout << i << " " << ans[i] << "\n";
    while (t --> 0) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}