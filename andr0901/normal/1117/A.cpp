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
    int n;
    cin >> n;
    vector <int> a(n);
    int k = -1;
    forn (i, 0, n) {
        cin >> a[i];
        k = max(k, a[i]);
    }
    a.pb(-1);
    int kek = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            int cnt = 0;
            forn (j, i, n + 1) {
                kek++;
                if (a[j] == k)
                    cnt++;
                else {
                    i = j;
                    break;
                }
            }
            ans = max(cnt, ans);
        }
    }
    cout << ans;
    return 0;
}