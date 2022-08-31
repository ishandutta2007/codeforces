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

const int MAXN = ((int) 2e5 + 7);
const int BIT = 30;
const int MAXV = MAXN * BIT;

int to[MAXV][2];
int dp[MAXV];
int sz = 1;

void add(int x) {
    int v = 0;
    ++dp[v];
    for (int i = BIT; i >= 0; --i) {
        int b = (x >> i) & 1;
        if (!to[v][b]) {
            to[v][b] = sz++;
        }
        v = to[v][b];
        ++dp[v];
    }
}

void del(int x) {
    int v = 0;
    --dp[v];
    for (int i = BIT; i >= 0; --i) {
        v = to[v][(x >> i) & 1];
        --dp[v];
    }
}

int ans(int x) {
    int v = 0;
    int ans = 0;
    for (int i = BIT; i >= 0; --i) {
        int b = (x >> i) & 1;
        if (to[v][b ^ 1] && dp[to[v][b ^ 1]] > 0) {
            ans = (ans << 1) + 1;
            v = to[v][b ^ 1];
        } else {
            ans = (ans << 1);
            v = to[v][b];
        }
    }
    return max(x, ans);
}

int main() {
    int q, x;
    scanf("%d", &q);
    char c;
    while (q--) {
        scanf(" %c", &c);
        if (c == '+') {
            scanf("%d", &x);
            add(x);
        } else if (c == '-') {
            scanf("%d", &x);
            del(x);
        } else {
            scanf("%d", &x);
            printf("%d\n", ans(x));
        }
    }
}