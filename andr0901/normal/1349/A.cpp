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

vector <bool> is_prime;

void sieve(int n) {
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    forn (i, 2, n + 1)
        if (is_prime[i] && 1LL * i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
}

long long bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a);
    long long t = bin_pow(a, p / 2);
    return (1LL * t * t);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int MAXN = 2e5 + 20;
    sieve(MAXN);   
    //cout << sz(p);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <vector <int>> b(MAXN);
    forn (i, 0, n) {
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                int cnt = 0;
                while (a[i] % j == 0) {
                    cnt++;
                    a[i] /= j;
                }
                b[j].pb(cnt);
            }
        }
        if (a[i] > 1)
            b[a[i]].pb(1);
    }
    long long ans = 1;
    forn (i, 0, MAXN) {
        sort(all(b[i]));
        //cout << i << ": " << b[i] << "\n";
        int t = n - sz(b[i]);
        if (t >= 2)
            continue;
        ans *= bin_pow(i, b[i][1 - t]);
    }
    cout << ans;
    return 0;
}