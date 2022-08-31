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
    vector <int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        b[i] ^= 1;
    }
    int i = 0;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        if (b[i] == 0) {
            cnt += 2;
            i++;
            while (i < n && b[i] == 0) i++, cnt++;
        }
    }
    if (cnt) cnt--;
    printf("%d\n", cnt);
}