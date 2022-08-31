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

int r[6][2];

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt = 0;
    for (int t = 2; t <= 5; t++) {
        while (a % t == 0) {
            r[t][0]++;
            a /= t;
        }
        while (b % t == 0) {
            r[t][1]++;
            b /= t;
        }
        cnt += max(r[t][0], r[t][1]) - min(r[t][0], r[t][1]);
    }
    if (a == b) {
        printf("%d\n", cnt);
    } else {
        puts("-1");
    }
}