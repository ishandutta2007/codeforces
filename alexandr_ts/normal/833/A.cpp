#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 1e3 + 10;
const int N = 1e6 + 10;


int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        ll x, y;
        int x1, y1;
        scanf("%d %d", &x1, &y1);
        x = x1, y = y1;
        ll tmp = pow(x * y, 1./3.);
        bool ok = false;
        frab(i, -2, 3)
            if ((tmp + i) * (tmp + i) * (tmp + i) == x * y)
                ok = true;
        if (x * x % y == 0 && y * y % x == 0 && ok)
            printf("Yes\n");
        else
            printf("No\n");
    }

}