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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    int n = a + b;
    --b;
    if (k == 0) {
        cout << "Yes\n";
        forn (i, 0, 2)
            cout << string(b + 1, '1') + string(a, '0') << "\n";
        return 0;
    }
    if (a == 0 || b == 0) {
        cout << "No\n";
        return 0;
    }
    vector<string> ans(2);
    ans[0] += '0';
    --a;
    ans[1] += '1';
    --b;
    forn (i, 0, k - 1) {
        if (a >= 1) {
            ans[0] += '0';
            ans[1] += '0';
            a--;
        } else if (b >= 1) {
            ans[0] += '1';
            ans[1] += '1';
            b--;;
        } else {
            cout << "No\n";
            return 0;
        }
    }
    ans[0] += '1';
    ans[1] += '0';

    ans[0] += string(a, '0');
    ans[1] += string(a, '0');
    ans[0] += string(b, '1');
    ans[1] += string(b, '1');

    ans[0] += '1';
    ans[1] += '1';

    cout << "Yes\n";
    forn (i, 0, 2) {
        reverse(all(ans[i]));
        cout << ans[i] << "\n";
    }
    return 0;
}