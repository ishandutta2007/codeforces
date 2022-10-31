#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int MAXN = 1e6 + 5, P = 307;
const int MOD = 998244353;

vector <int> p;

void init_p() {
    p.resize(MAXN);
    p[0] = 1;
    forn (i, 1, sz(p))
        p[i] = (1LL * p[i - 1] * P) % MOD;
}

int char_to_int(char c) {
    return ((int)c + 1);
}

void add(vector <int>& h, const string& s) {
    forn (i, 0, sz(s))
        h.pb((1LL * h.back() * P + char_to_int(s[i])) % MOD);
}

int get(const vector <int>& h, int l, int r) {
    return (h[r] - (1LL * h[l] * p[r - l]) % MOD + MOD) % MOD;
}

vector <int> init_h(const string& s) {
    vector <int> h(sz(s) + 1);
    forn (i, 1, sz(h))
        h[i] = (1LL * h[i - 1] * P + char_to_int(s[i - 1])) % MOD;
    return h;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string ans;
    vector <int> h = {0};
    init_p();
    forn (_, 0, n) {
        string s;
        cin >> s;
        vector <int> hs = init_h(s);
        for (int i = min(sz(ans), sz(s)); i >= 0; i--) {
            if (get(hs, 0, i) == get(h, sz(ans) - i, sz(ans))) {
                for (int j = 0; j < i; j++) 
                    ans.pop_b(), h.pop_b();
                add(h, s);
                ans += s;
                break;
            }
        }
        //cout << ans << "  " << sz(h) << "\n";
    }
    cout << ans;
    return 0;
}