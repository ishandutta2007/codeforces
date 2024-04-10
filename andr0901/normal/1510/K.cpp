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

int n;

void op1(vector<int>& a) {
    for (int i = 0; i + 1 < n; i += 2) {
        swap(a[i], a[i + 1]);
    }
}

void op2(vector<int>& a) {
    forn (i, 0, n / 2) {
        swap(a[i], a[i + n / 2]);
    }
}

bool is_sorted(vector<int>& a) {
    forn (i, 0, n) {
        if (a[i] != i + 1) {
            return false;
        }
    }
    return true;
}

constexpr int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    n *= 2;
    vector<int> a(n);
    cin >> a;
    vector<int> b = a;
    int ans = INF;
    forn (i, 0, n) {
        if (is_sorted(a)) {
            chkmin(ans, i);
            break;
        }
        if (is_sorted(b)) {
            chkmin(ans, i);
            break;
        }
        if (i % 2) {
            op1(a);
            op2(b);
        } else {
            op2(a);
            op1(b);
        }
    }
    cout << (ans == INF ? -1 : ans);
    return 0;
}