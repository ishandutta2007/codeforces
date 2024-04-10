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

bool check_badness(const string& s, int i) {
    if (i + 2 >= s.size()) {
        return false;
    }
    return s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<bool> starts_bad(n);
    int ans = 0;
    forn (i, 0, n) {
        starts_bad[i] = check_badness(s, i);
        ans += starts_bad[i];
    }
    while (q --> 0) {
        int pos;
        char symb;
        cin >> pos >> symb;
        --pos;
        s[pos] = symb;
        forn (i, max(0, pos - 4), min(n, pos + 4)) {
            ans -= starts_bad[i];
            starts_bad[i] = check_badness(s, i);
            ans += starts_bad[i];
        }
        cout << ans << "\n";
    }
    return 0;
}