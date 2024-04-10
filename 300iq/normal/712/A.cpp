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

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n), b(n);
    for (auto &x : a) {
        scanf("%d", &x);
    }
    for (int i = 0; i < n - 1; i++) {
        a[i] += a[i + 1];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}