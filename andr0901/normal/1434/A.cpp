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

constexpr int INF = 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector <int> a(6);
    cin >> a;
    int n;
    cin >> n;
    vector <int> b(n);
    cin >> b;
    sort(all(a)), sort(all(b));
    vector <deque <int>> points(n); 
    multiset <int> open;
    vector <pii> events;
    forn (i, 0, n) {
        forn (j, 0, 6) {
            points[i].pb(b[i] - a[j]);
            events.eb(points[i].back(), i);
        }
        open.insert(points[i].back());
    }
    int ans = INF;
    sort(all(events));
    for (auto [x, idx] : events) {
        if (open.size() < n)
            break;
        cerr << x << " " << *open.rbegin() << "\n";
        chkmin(ans, *open.rbegin() - x);
        open.erase(open.find(points[idx].back()));
        points[idx].pop_back();
        if (!points[idx].empty())
            open.insert(points[idx].back());
    }
    cout << ans;
    return 0;
}