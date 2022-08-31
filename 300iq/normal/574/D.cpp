#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define nfor(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    int n;
    scanf("%d", &n);
    vector <int> h(n), res(n);
    forn (i, n) {
        scanf("%d", &h[i]);
    }
    int bad = 0;
    int ans = 0;
    forn (i, n) {
        bad = min(bad, h[i] - i - 1);
        res[i] = i + 1 + bad;
    }
    bad = n + 1;
    nfor (i, n) {
        bad = min(bad, h[i] + i + 1);
        res[i] = min(res[i], bad - i - 1);
        ans = max(ans, res[i]);
    }
    printf("%d\n", ans);
}