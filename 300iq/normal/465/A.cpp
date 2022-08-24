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

const int MAXN = (int) 100 + 7;

int main() {
    int n;
    scanf("%d", &n);
    char c[MAXN];
    scanf(" %s", c);
    int lim = n - 1;
    for (int i = 0; c[i]; i++) {
        lim = min(lim, (c[i] == '0' ? i : lim));
    }
    printf("%d\n", lim + 1);
}