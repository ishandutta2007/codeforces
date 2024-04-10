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
#define int long long

const int MAXN = 1e6 + 5, P = 29;
vector <int> p;

void init_p(const int MOD = 1e9 + 7) {
    p.resize(MAXN);
    p[0] = 1;
    forn (i, 1, sz(p))
        p[i] = (1LL * p[i - 1] * P) % MOD;
}

int char_to_int(char c) {
    return (c - 'a' + 1);
}

vector <int> init_h(const string& s, const int MOD = 1e9 + 7) {
    vector <int> h(sz(s) + 1);
    forn (i, 1, sz(h))
        h[i] = (1LL * h[i - 1] * P + char_to_int(s[i - 1])) % MOD;
    return h;
}

int get(const vector <int>& h, int l, int r, const int MOD = 1e9 + 7) {
    return (h[r] - (1LL * h[l] * p[r - l]) % MOD + MOD) % MOD;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    if (a[0] == '1') {
        forn (i, 0, sz(a)) {
            if (a[i] == '1')
                a[i] = '0';
            else 
                a[i] = '1';
        }
    }
    init_p();
    vector <int> h = init_h(b);
    int cnt0 = 0, cnt1 = 0;
    forn (i, 0, sz(a)) {
        if (a[i] == '0')
            cnt0++;
        else 
            cnt1++;
    }
    int ans = 0;
    forn (len0, 1, sz(b)) {
        if ((sz(b) - 1LL * len0 * cnt0) % cnt1)
            continue;
        if (len0 * cnt0 >= sz(b))
            continue;
        int len1 = (sz(b) - 1LL * len0 * cnt0) / cnt1;
        if (!(0 < len1 && len1 < sz(b)))
            continue;
        //cout << len0 << " " << len1 << ":\n";
        int h0 = get(h, 0, len0), h1 = -1;
        int j = 0;
        bool ok = 1;
        forn (i, 0, sz(a)) {
            //cout << i << " " << j << "\n";
            if (a[i] == '0') {
                if (get(h, j, j + len0) != h0) {
                    ok = 0;
                    break;
                }
                j += len0;
            } else {
                if (h1 == -1) 
                    h1 = get(h, j, j + len1);
                if (get(h, j, j + len1) != h1) {
                    ok = 0;
                    break;
                }
                j += len1;
            }
        }
        //cout << j << "  " << h0 << " " << h1 << "\n";
        if (ok) {
            if (h0 != h1)
                ans++;
        }
    }
    cout << ans;
    return 0;
}