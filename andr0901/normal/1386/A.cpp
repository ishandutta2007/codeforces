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

long long n;
long long cur;

int ask(long long x) {
    // assert(1 <= x && x <= n);
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    cur = x;
    return ans;
}

bool increase = true;

bool check(long long m) {
    int ans;
    if (increase)
        ans = ask(cur + m);
    else
        ans = ask(cur - m);
    increase = !increase;
    return ans;
}

long long sim_cur;

bool sim_increase, sim_ok;

int sim_ask(long long x) {
    if (!(1 <= x && x <= n))
        sim_ok = false;
    sim_cur = x;
    return 0;
}

bool sim_check(long long m) {
    int ans;
    if (sim_increase)
        ans = sim_ask(sim_cur + m);
    else
        ans = sim_ask(sim_cur - m);
    sim_increase = !sim_increase;
    return ans;
}

bool simulate(long long x) {
    sim_ok = sim_increase = true;
    sim_ask(x);
    long long l = 0, r = n;
    while (r - l > 1) {
        long long m = l + r >> 1;
        if (sim_check(m))
            r = m;
        else
            l = m;
    }
    return sim_ok;
}

void solve() {
    cin >> n;
    if (n == 2) {
        ask(1);
        if (ask(2))
            cout << "= 1" << endl;
        else
            cout << "= 2" << endl;
        return;
    }
    long long start = n / 3;
    forn (d, -1000, 1000) {
        if (simulate(start + d)) {
            start += d;
            break;
        }
    }
    cerr << start << "\n";
    ask(start);
    increase = true;
    long long l = 0, r = n;
    while (r - l > 1) {
        long long m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << "= " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}