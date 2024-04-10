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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n % k) {
        cout << "-1\n";
        return;
    }
    for (char &c : s)
        c -= 'a';
    vector<int> pref(26);
    forn (i, 0, n)
        pref[s[i]]++;
    bool already_done = true;
    forn (i, 0, 26)
        if (pref[i] % k)
            already_done = false;
    if (already_done) {
        for (char c : s)
            cout << (char)(c + 'a');
        cout << "\n";
        return;
    }
    int free = 0;
    for (int i = n - 1; i >= 0; --i) {
        pref[s[i]]--;
        forn (j, s[i] + 1   , 26) {
            pref[j]++;
            int needed = 0;
            forn (l, 0, 26)
                needed += (pref[l] + k - 1) / k * k - pref[l];
            if (needed <= free) {
                cerr << i << " " << j << "  " << needed << " " << free << "\n";
                forn (l, 0, i)
                    cout << (char)(s[l] + 'a');
                cout << (char)(j + 'a');
                cout << string(free - needed, 'a');
                forn (l, 0, 26)
                    cout << string((pref[l] + k - 1) / k * k - pref[l], (char)(l + 'a'));
                cout << "\n";
                return;
            }
            pref[j]--;
        }
        ++free;
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}