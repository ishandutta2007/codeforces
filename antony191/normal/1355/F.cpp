#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

const int N = 1000;
vector<int> pr;
vector<ll> mn;
int lp[N];
void precalc() {
    for (int i = 2; i < N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++)
            lp[i * pr[j]] = pr[j];
    }
    ll k = 1;
    for (int i = 0; pr[i] < 178; i++) {
        ld tmp = (ld)k * (ld)pr[i];
        if (tmp >= 1e18) {
            mn.push_back(k);
            k = 1;
        }
        k *= pr[i];
    }
    mn.push_back(k);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int t;
    cin >> t;
    while(t--) {
        int cnt = 0;
        vector<int> a;
        ll k = 1;
        int ans = 1;
        forn(i, mn.size()) {
            cout << "? " << mn[i] << endl;
            cnt++;
            ll tmp;
            cin >> tmp;
            k *= tmp;
        }
        forn(i, pr.size()) {
            if (pr[i] > 178) break;
            if (k % pr[i] == 0) {
                a.push_back(pr[i]);
                ans *= 2;
            }
        }
        shuffle(all(a), rnd);
        for (auto i : a) {
            if (k * i > inf) continue;
            k /= i;
            ll tmp = 1;
            while(tmp * k <= inf) {
                tmp *= i;
            }
            tmp /= i;
            cout << "? " << tmp << endl;
            cin >> tmp;
            int l = 0;
            while(tmp > 1) {
                l++;
                tmp /= i;
            }
            forn(j, l) k *= i;
            ans /= 2;
            ans *= l + 1;
        }
        if (k * 179ll * 179ll * 179ll > inf) {
            cout << "! " << 2 * ans << endl;
            continue;
        }
        if (ans <= 2) {
            cout << "! " << (ans * 9) / 2 << endl;
            continue;
        }
        vector<int> qr;
        ll c = 1;
        bool ok = false;
        forn(i, pr.size()) {
            if (pr[i] < 178) continue;
            if (k * pr[i] * pr[i] * pr[i] > inf) break;
            qr.push_back(pr[i]);
        }
        shuffle(all(qr), rnd);
        for (auto i : qr) {
            ld tmp = (ld)c * (ld)i;
            if (tmp >= 1e18) {
                if (cnt >= 22) {
                    cerr << "Not enough" << endl;
                    break;
                }
                cout << "? " << c << endl;
                cnt++;
                ll q;
                cin >> q;
                if (q > 1) {
                    ok = true;
                    break;
                }
                c = 1;
            }
            c *= i;
        }
        if (c > 1) {
            if (cnt >= 22) {
                cerr << "Not enough" << endl;
                break;
            }
            cout << "? " << c << endl;
            cnt++;
            ll q;
            cin >> q;
            if (q > 1) {
                ok = true;
            }
        }
        if (ok) cout << "! " << 4 * ans << endl;
        else cout << "! " << 2 * ans << endl;
    }
    return 0;
}