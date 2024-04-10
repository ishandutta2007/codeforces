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
    int n, q;
    cin >> n >> q;
    multiset <int> s;
    forn (i, 0, n) {
        int x;
        cin >> x;
        s.insert(x);
    }
    multiset <int> dst;
    int prev = -1;
    for (int x : s) {
        if (prev != -1)
            dst.insert(x - prev);
        prev = x;
    }
    if (s.size() < 2)
        cout << 0;
    else {
        cout << *s.rbegin() - *s.begin() - *dst.rbegin();
    }
    cout << "\n";
    while (q --> 0) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 0) {
            int low = -1, up = -1;
            if (s.upper_bound(x) != s.end())
                up = *s.upper_bound(x);
            if (up != -1)
                dst.erase(dst.find(up - x));
            
            if (s.lower_bound(x) != s.begin())
                low = *--s.lower_bound(x);
            if (low != -1)
                dst.erase(dst.find(x - low));

            if (up != -1 && low != -1)
                dst.insert(up - low);

            s.erase(s.find(x));
        } else {
            int low = -1, up = -1;
            if (s.upper_bound(x) != s.end())
                up = *s.upper_bound(x);
            if (up != -1)
                dst.insert(up - x);
            
            if (s.lower_bound(x) != s.begin())
                low = *--s.lower_bound(x);
            if (low != -1)
                dst.insert(x - low);

            if (up != -1 && low != -1)
                dst.erase(dst.find(up - low));

            s.insert(x);
        }

        if (s.size() < 2)
            cout << 0;
        else {
            cout << *s.rbegin() - *s.begin() - *dst.rbegin();
        }
        cout << "\n";
    }
    return 0;
}