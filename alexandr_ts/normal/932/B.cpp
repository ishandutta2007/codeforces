#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int P = 29;
const int N = 1e6 + 10;

vector <int> g[20];

int f[N];
int calc(int x) {
    int ans = 1;
    while (x) {
        if (x % 10)
            ans *= (x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    for (int i = 1; i < 10; i++) {
        f[i] = i;
        g[i].pb(i);
    }
    for (int i = 10; i < N; i++) {
        int tmp = f[calc(i)];
        f[i] = tmp;
        g[tmp].pb(i);
    }
    int q;
    scanf("%d", &q);
    int l, r, k;
    for (int i = 0; i< q; i++) {
        scanf("%d %d %d", &l, &r, &k);
        cout << max(0, upper_bound(g[k].begin(), g[k].end(), r) -
            lower_bound(g[k].begin(), g[k].end(), l)) << "\n";
    }
}