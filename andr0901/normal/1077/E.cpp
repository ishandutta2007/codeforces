#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long

/*int nearestPow(int n) {
    int k = 1;
    while (k < n)
        k *= 2;
    if (n == k)
        return n;
    return k / 2;
}*/

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map <int, int> m;
    forn (i, 0, n) {
        int t;
        cin >> t;
        m[t]++;
    }
    vector <int> a;
    for (pii p : m)
        a.push_back(p.sc);
    sort(a.rbegin(), a.rend());
    int ans = INT_MIN;
    forn (i, 1, a[0] + 1) {
        int curAns = i;
        int cur = i;
        forn (j, 1, a.size()) {
            if (cur % 2)
                break;
            cur /= 2;
            if (a[j] < cur)
                break;
            curAns += cur;
        }
        ans = max(ans, curAns);
    }
    cout << ans;
    return 0;
}