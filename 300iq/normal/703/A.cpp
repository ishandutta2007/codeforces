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
    int n, c1 = 0, c2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m, c;
        scanf("%d%d", &m, &c);
        c1 += (m > c), c2 += (m < c);
    }
    puts(c1 > c2 ? "Mishka" : c1 < c2 ? "Chris" : "Friendship is magic!^^");
}