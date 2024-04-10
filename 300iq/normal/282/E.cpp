#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int N = (int) 1e5 + 7;
const int K = 50;
const int MAXV = N * K;
int to[MAXV][2];
int sz = 1;
int cnt[MAXV];

void ch(ll n, int d) {
    int v = 0;
    cnt[v] += d;
    for (int i = K - 1; i >= 0; i--) {
        int b = (n >> i) & 1;
        if (!to[v][b]) to[v][b] = sz++;
        v = to[v][b];
        cnt[v] += d;
    }
}

ll res(ll n) {
    int v = 0;
    ll ans = 0;
    for (int i = K - 1; i >= 0; i--) {
        int b = (n >> i) & 1;
        b ^= 1;
        if (to[v][b] && cnt[to[v][b]] > 0) {
            v = to[v][b]; 
            ans = ans * 2 + 1;
        } else {
            v = to[v][!b];
            ans = ans * 2 + 0;
        }
    }
    return ans;
}


int main() {
    int n;
    scanf("%d", &n);
    vector <ll> a(n + 1);
    vector <ll> pref(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll x = 0;
    for (int i = 0; i <= n; i++) ch(x ^ a[i], 1), x ^= a[i], pref[i] = x;
    ll ans = 0;
    ll sum = 0; 
    ans = max(ans, res(0));
    for (int i = n; i >= 0; i--) {
        sum ^= a[i];
        ch(pref[i], -1);
        ans = max(ans, res(sum));
    }
    printf("%lld\n", ans); 
}