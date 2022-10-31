//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

const int MAXN = 1e6 + 5, MOD = 1e9 + 9, P = 41;

vector <int> p;

void init_p() {
    p.resize(MAXN);
    p[0] = 1;
    forn (i, 1, sz(p))
        p[i] = (1LL * p[i - 1] * P) % MOD;
}

int char_to_int(char c) {
    return (c - 'a' + 1);
}

vector <int> init_h(const string& s) {
    vector <int> h(sz(s) + 1);
    forn (i, 1, sz(h))
        h[i] = (1LL * h[i - 1] * P + char_to_int(s[i - 1])) % MOD;
    return h;
}

int get(const vector <int>& h, int l, int r) {
    return (h[r] - (1LL * h[l] * p[r - l]) % MOD + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    init_p();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> delta(n + 1);
    auto h = init_h(s);
    forn (len, 1, n + 1) {
        if (k * len > n)
            break;
        bool ok = true;
        int sample = get(h, 0, len);
        forn (i, 0, k) {
            int l = i * len, r = (i + 1) * len;
            if (get(h, l, r) != sample) {
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;
        int l = len * k, r = n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (get(h, len * k, m) == get(h, 0, m - len * k))
                l = m;
            else
                r = m; 
        }
        cerr << "ok: " << len << " " << " " << len * k << " " << l << "\n";
        delta[len * k - 1]++;
        delta[min(len * k + len, l)]--;
    }
    int bal = 0;
    forn (i, 0, n) {
        bal += delta[i];
        if (bal)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}