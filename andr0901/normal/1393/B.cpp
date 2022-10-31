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
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <int> freq(1e5 + 50);
    multiset <int> s;
    forn (i, 0, n)
        freq[a[i]]++;
    for (auto i : freq)
        s.insert(i);
    int q;
    cin >> q;
    while (q --> 0) {
        char tp;
        int x;
        cin >> tp >> x;
        if (tp == '-') {
            s.erase(s.find(freq[x]));
            freq[x]--;
            s.insert(freq[x]);
        } else {
            s.erase(s.find(freq[x]));
            freq[x]++;
            s.insert(freq[x]);
        }
        if (s.empty()) {
            cout << "NO\n";
            continue;
        }
        int t = *--s.end();
        s.erase(--s.end());
        if (t >= 8) {
            cout << "YES\n";
            s.insert(t);
            continue;
        }
        if (t < 4) {
            cout << "NO\n";
            s.insert(t);
            continue;
        }
        if (s.empty()) {
            cout << "NO\n";
            s.insert(t);
            continue;
        }

        int p = *--s.end();
        s.erase(--s.end());
        if (p >= 4 || p >= 2 && t - 4 >= 2) {
            cout << "YES\n";
            s.insert(t), s.insert(p);
            continue;
        }
        if (p < 2) {
            cout << "NO\n";
            s.insert(t), s.insert(p);
            continue;
        }
        if (s.empty()) {
            cout << "NO\n";
            s.insert(t), s.insert(p);
            continue;
        }

        int q = *--s.end();
        s.erase(--s.end());
        if (q >= 2) {
            cout << "YES\n";
            s.insert(t), s.insert(p), s.insert(q);
            continue;
        }
        if (q < 2) {
            cout << "NO\n";
            s.insert(t), s.insert(p), s.insert(q);
            continue;
        }
        cerr << "kek\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    while (t --> 0)
        solve();
    return 0;
}