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

#define int int64_t

int t;

void print(int days) {
    cerr << days << "\n";
    cout << (days >= t ? "Yes" : "No") << "\n";
    exit(0);
}

void yes() {
    cout << "Yes\n";
    exit(0);
}

void no() {
    cout << "No\n";
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int k, l, r, x, y;
    cin >> k >> l >> r >> t >> y >> x;
    k -= l, r -= l;
    if (x < y) {
        if (k + x <= r)
            k += x;
        int per_day = y - x;
        print((k - (y - 1) + per_day - 1) / per_day);
    } else {
        if (r >= x + y)
            yes();
        int days = 0;
        set <int> used;
        while (true) {
            int lowest = k % y;
            cerr << lowest << " ";
            if (used.find(lowest) != used.end())
                yes();
            used.insert(lowest);
            days += (k - lowest) / y;
            if (lowest + x > r)
                print(days);            
            k = lowest + x;
        }
    }
    return 0;
}