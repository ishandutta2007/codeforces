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
    int x, y;
    int s1 = 0, s2 = 0;
    bool b1 = 0, b2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        s1 += x, s2 += y;
        b1 |= (s1 % 2 == 0 && s2 % 2 == 1);
        b2 |= (s1 % 2 == 1 && s2 % 2 == 0);
    }
    if (s1 % 2 == 0 && s2 % 2 == 0) {
        puts("0");
    } else if (s1 % 2 == 1 && s2 % 2 == 1) {
        if (b1 || b2) {
            puts("1");
        } else {
            puts("-1");
        }
    } else {
        puts("-1");
    }
}