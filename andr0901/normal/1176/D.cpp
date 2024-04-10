#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <int> is_prime;

void sieve() {
    const int N = 3e6;
    is_prime.resize(N, -1);
    is_prime[0] = is_prime[1] = 0;
    int cnt = 1;
    forn (i, 2, N) {
        if (is_prime[i] == -1) {
            is_prime[i] = cnt++;
            for (int j = 2 * i; j <= N; j += i)
                is_prime[j] = 0;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    sieve();
    int n;
    cin >> n;
    multiset <int> a;
    forn (i, 0, 2 * n) {
        int t;
        cin >> t;
        a.insert(t);
    }
    vector <int> ans;
    forn (i, 0, n) {
        int x = *a.rbegin();
        //cout << x << " " << is_prime[x] << "\n";
        if (is_prime[x]) {
            ans.pb(is_prime[x]);
            a.erase(a.find(is_prime[x]));
        } else {
            int mx = -1;
            for (int j = 2; j * j <= x; j++) 
                if (x % j == 0)
                    mx = max({mx, j, x / j});
            ans.pb(x);
            a.erase(a.find(mx));
        }
        a.erase(a.find(x));
    }
    for (int i : ans)
        cout << i << " ";
    return 0;
}