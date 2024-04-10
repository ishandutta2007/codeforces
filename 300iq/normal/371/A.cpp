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

int t[100 + 7][3];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        t[i % k][a[i] - 1]++;
        t[i % k][2]++;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += t[i % k][2] - max(t[i % k][1], t[i % k][0]);
    }
    printf("%d\n", ans);
}