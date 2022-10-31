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

int MOD;

int bin_pow(int a, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    return (1LL * bin_pow(a, p / 2) * bin_pow(a, p / 2)) % MOD;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> MOD;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];

    sort(all(a));
    vector <long long> cnt(MOD);
    vector <long long> ans(MOD);
    forn (i, 0, n) {
        a[i] %= MOD;
        forn (j, 0, MOD) {
            ans[(a[i] - j + MOD) % MOD] += cnt[j];
            //ans = (ans * pow[(a[i] - j + MOD) % MOD][cnt[j]]) % MOD; 
            //ans = (ans * (bin_pow((a[i] - j + MOD) % MOD, cnt[j]))) % MOD;
        }
        cnt[a[i]]++;
    }
    int p = 1;
    forn (i, 0, MOD)
        p = (p * bin_pow(i, ans[i])) % MOD;
    cout << p;
    return 0;
}