#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 333

int n, i;
int l[maxN], c[maxN];
map<int, int> M;
int ans = 1 << 30;

vector< pair<int, int> > rez;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

void upd(int x, int y) {
    if (M[x] == 0)
        M[x] = y;
    else
        M[x] = min(M[x], y);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &l[i]);
    for (i = 1; i <= n; i++) scanf("%d", &c[i]);

    for (i = 1; i <= n; i++) {
        upd(l[i], c[i]);

        rez.clear();
        for (auto e : M)
            rez.pb(mp(gcd(e.first, l[i]), e.second + c[i]));

        for (auto e : rez)
            upd(e.first, e.second);
    }

    if (M[1] == 0) {
        printf("-1");
        return 0;
    }

    printf("%d", M[1]);


    return 0;
}