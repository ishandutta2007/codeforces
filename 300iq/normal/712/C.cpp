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
    int x, y;
    scanf("%d%d", &x, &y);
    swap(x, y);
    int a = x, b = x, c = x;
    int cnt = 0;
    while (a != y || b != y || c != y) {
        if (a > b) {
            swap(a, b);
        }
        if (a > c) {
            swap(a, c);
        }
        int pa = a;
        a = min(y, b + c - 1);
        if (a != pa) cnt++;
    }
    printf("%d\n", cnt);
}