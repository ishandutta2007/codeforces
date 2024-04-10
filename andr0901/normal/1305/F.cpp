#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <long long> get(long long x) {
    vector <long long> ans;
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0)
                x /= i;
            ans.pb(i);
        }
    }
    if (x > 1)
        ans.pb(x);
    return ans;
}

mt19937 rnd(time(0));

long long ans = 1e18;
vector <long long> a;

void check(long long x) {
    if (x < 1)
        return;
    auto divisors = get(x);
    for (auto& t : divisors) {
        long long cur= 0;
        for (long long k : a) {
            long long down = k / t * t, up = (k + t - 1) / t * t;
            if (!down)
                cur += up - k;
            else
                cur += min(up - k, k - down);
        }
        chkmin(ans, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    cin >> a;
    forn (_, 0, 10) {
        int i = rnd() % n;
        check(a[i] - 1);
        check(a[i]);
        check(a[i] + 1);
    }
    cout << ans;
    return 0;
}