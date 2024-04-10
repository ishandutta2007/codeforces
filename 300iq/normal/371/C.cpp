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

int a, b, d;
int e, f, g;
const int MAXN = (int) 100 + 7;
char c[MAXN];
int cnt[255];

string get() {
    scanf("%s", c);
    return string(c);
}

ll check(ll x) {
    ll sum = 0;
    sum += max(0ll, (cnt[(int) 'B'] * x - a)) * e;
    sum += max(0ll, (cnt[(int) 'S'] * x - b)) * f;
    sum += max(0ll, (cnt[(int) 'C'] * x - d)) * g;
    return sum;
}

int main() {
    string s = get();
    for (auto c : s) {
        cnt[(int) c]++;
    }
    scanf("%d%d%d%d%d%d", &a, &b, &d, &e, &f, &g);
    ll r;
    scanf("%lld", &r);
    ll vl = 0, vr = 1e15;
    while (vr - vl > 1) {
        ll vm = (vl + vr) >> 1ll;
        if (check(vm) <= r) {
            vl = vm;
        } else {
            vr = vm;
        }
    }
    printf("%lld\n", vl);
}