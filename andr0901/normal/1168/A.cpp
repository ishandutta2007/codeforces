#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int n, m;

bool check(vector <int> a, int mid) {
    forn (i, 1, n + 1) {
        if (a[i] > a[i - 1]) {
            if ((a[i] + mid) >= m && (a[i] + mid) % m >= a[i - 1])
                a[i] = a[i - 1];
        } else {
            if (-a[i] + a[i - 1] > mid)
                return 0;
            a[i] = a[i - 1];
        }
    }
    /*cout << mid << "\n";
    forn (i, 0, n + 1)
        cout << a[i] << " ";
    cout << "\n";*/
    forn (i, 0, n)
        if (a[i] > a[i + 1])
            return 0;
    return 1;
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vector <int> a(n + 1);
    forn (i, 1, n + 1) 
        cin >> a[i];
    int l = -1, r = m;
    while (r - l > 1) {
        //cout << l << " " << r << "\n";
        int mid = (l + r) / 2;
        if (check(a, mid))
            r = mid;
        else 
            l = mid;
    }
    cout << r;
    return 0;
}