#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000, mod = 1000'000'007;
const ll llinf = 1e18;
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

int N;
int lp[100001];
vector<int> pr;
const int C = 100;
void precalc() {
    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; j++)
            lp[i * pr[j]] = pr[j];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    N = n;
    precalc();
    int ans = 1;
    int cnt = n;
    bool ok = false;
    int k = (int)pr.size();
    for (int i = (int)pr.size() - 1; i >= 0; i--) {
        cout << "B " << pr[i] << endl;
        int tmp;
        cin >> tmp;
        cnt -= tmp;
        assert(k > 0);
        if ((pr[k - 1] * 1ll * pr[k - 1] > (ll)n) && !ok) {
            if (((int)pr.size() - i) % C == 0 || i == 0) {
                cout << "A 1" << endl;
                cin >> tmp;
                if (tmp > cnt)
                    for (int j = i; j < i + C && j < k; j++) {
                        if (pr[j] * 1ll * pr[j] <= (ll)n) continue;
                        cout << "A " << pr[j] << endl;
                        cin >> tmp;
                        if (tmp == 1) {
                            assert(ans % pr[j] != 0);
                            ans *= pr[j];
                            ok = true;
                            break;
                        }
                    }
                uin(k, i);
            }
        }
        if (pr[i] * 1ll * pr[i] > n) continue;
        int c = pr[i];
        for (int j = 0; c <= n; j++) {
            cout << "A " << c << endl;
            cin >> tmp;
            if (!tmp) break;
            ans *= pr[i];
            c *= pr[i];
        }
    }
    cout << "C " << ans << endl;
    return 0;
}