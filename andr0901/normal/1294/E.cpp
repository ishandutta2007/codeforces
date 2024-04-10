#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int n;

int dst(int real, int y) {
    if (real <= y)
        return y - real;
    else
        return y + (n - real);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    forn (i, 0, n)
        forn (j, 0, m)
            cin >> a[i][j];
    long long ans = 0;
    forn (j, 0, m) {
        map <int, int> real_place;
        int cur = j + 1;
        forn (i, 0, n) {
            real_place[cur] = i;
            cur += m;
        }
        vector <int> cnt(n);
        forn (i, 0, n)
            if (real_place.find(a[i][j]) != real_place.end())
                cnt[dst(real_place[a[i][j]], i)]++;
        cur = n;
        forn (i, 0, n)
            cur = min(cur, i + (n - cnt[i]));
        ans += cur;
    }
    cout << ans;
    return 0;
}