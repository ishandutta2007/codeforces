#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define err(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int N = 2e5;

vector<int> v[N];

int q[N];
int st = 0, en = 0;

int a[N];
int u[N];

int main()
{
    #ifdef amit
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) a[i]--;
    int j = 1;
    u[0] = 1;
    int ok = 1;
    forn(ii, n) {
        int x = a[ii];
        if (!u[x] || ii == j) {
            ok = 0;
            break;
        }
        vector<int> z1;
        for (int y : v[x]) if (!u[y]) z1.push_back(y);
        if (j + (int)z1.size() > n) {
            ok = 0;
            break;
        }
        vector<int> z2;
        forn(_, (int)z1.size()) {
            z2.push_back(a[j++]);
        }
        sort(z1.begin(), z1.end());
        sort(z2.begin(), z2.end());
        forn(i, (int)z1.size()) {
            if (z1[i] != z2[i]) {
                ok = 0;
            }
        }
        if (!ok) break;
        for (int y : z1) u[y] = 1;
    }
    if (ok) printf("Yes\n");
    else printf("No\n");


                
                
    return 0;
}