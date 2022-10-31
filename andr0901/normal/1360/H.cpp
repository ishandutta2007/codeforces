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

void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        int x;
        cin >> x;
        cout << (x ^ 1) << "\n";
        return;   
    }
    map <long long, bool> used;
    long long sz = (1LL << m);
    long long mid = sz / 2 - 1;
    auto nxt = [&](long long x) -> long long {
        x++;
        while (used[x])
            x++;
        return x;
    };
    auto prev = [&](long long x) -> long long {
        x--;
        while (used[x])
            x--;
        return x;
    };
    forn (i, 0, n) {
        string s;
        cin >> s;
        reverse(all(s));
        long long cur = 0;
        forn (i, 0, m)
            if (s[i] == '1')
                cur += (1LL << i);
        if (cur < mid) {
            if (sz % 2 == 0) {
                mid = nxt(mid);
            }
        } else if (cur == mid) {
            if (sz % 2 == 0)
                mid = nxt(mid);
            else
                mid = prev(mid);
        } else {
            if (sz % 2)
                mid = prev(mid);
        }
        sz--;
        used[cur] = true;
        //cout << mid << " ";
    }
    string ans;
    forn (i, 0, m) {
        ans += (mid % 2) + '0';
        mid /= 2;
    }
    reverse(all(ans));
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}