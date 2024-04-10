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

/*
int print(int x) {
    vector <int> ans;
    while (x) {
        ans.pb(x % 2);
        x /= 2;
    }
    reverse(all(ans));
    for (int i : ans)
        cout << i;
    cout << "\t";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector <bool> used(1000);
    forn (iter, 1, 90) {
        forn (i, 1, 1000) {
            forn (j, 1, 1000) {
                forn (k, 1, 1000) {
                    if ((i ^ j ^ k) == 0 &&
                        !used[i] && !used[j] && !used[k]) {
                        cout << iter << ":\t";
                        print(i), print(j), print(k);
                        cout << "\n";
                        used[i] = used[j] = used[k] = true;
                        goto t;
                    }
                }
            }
        }
        t: {}
    }
    return 0;
}*/

#define int long long

void solve() {
    int n;
    cin >> n;
    int row = (n + 2) / 3;
    int s = 0, i = 0;
    while (true) {
        if (s + (1LL << i) >= row)
            break;
        s += (1LL << i);
        i += 2;
    }
    int rest = row - s - 1, ans = 0;
    if (n % 3 == 1) {
        ans += (1LL << i);
        ans += rest;
    } else if (n % 3 == 2) {
        ans += (1LL << (i + 1));
        for (int j = 0; j < i; j += 2) {
            int shift = j + 2;
            if (rest % (1LL << shift) >= (1LL << (shift - 1)))
                ans += (1LL << j);
            if ((rest + (1LL << shift - 2)) % (1LL << shift) >= (1LL << (shift - 1)))
                ans += (1LL << (j + 1));
        }
    } else if (n % 3 == 0) {
        ans += (1LL << (i + 1)) + (1LL << i);
        for (int j = 0; j < i; j += 2) {
            int shift = j + 2;
            if ((rest + (1LL << (shift - 2))) % (1LL << shift) >= (1LL << (shift - 1)))
                ans += (1LL << j);
        }
        for (int j = 1; j < i; j += 2) {
            int shift = j;
            if (rest % (1LL << shift) >= (1LL << (shift - 1)))
                ans += (1LL << j);
        }
    }
    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}