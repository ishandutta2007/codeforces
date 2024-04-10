#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 1e6+1;
const int INF = 1e9;

int x[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int cur = 1;
    bool ok = true;
    set <int> ps;
    fr(i, m) {
        scanf("%d", &x[i]);
        ps.insert(x[i]);
    }
    if (ps.count(1))
        ok = false;
    fr(i, k) {
        int v, u;
        scanf("%d %d", &v, &u);
        if (ok)
            if (v == cur)
                cur = u;
            else if (u == cur)
                cur = v;
        if (ps.count(cur))
            ok = false;
    }
    printf("%d", cur);
}