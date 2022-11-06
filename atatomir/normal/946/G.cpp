#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define inf 1000000000

int n, i;
int v[maxN];

int sz, s[maxN];
int l[maxN], r[maxN];
int ans;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);

    /*cout << 200000 << '\n';
    for (i = 1; i <= 200000; i++) cout << i + 13 << ' ';
    return 0;*/


    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]), v[i] -= i, v[i] += n + 1;

    //! left -> right
    sz = 0;
    for (i = 1; i <= n; i++) {
        int p = upper_bound(s + 1, s + sz + 1, v[i]) - s;
        if (sz < p) sz++;
        s[p] = v[i];
        l[i] = p;
    }

    //! right -> left
    sz = 0;
    for (i = n; i > 0; i--) {
        int p = upper_bound(s + 1, s + sz + 1, v[i], cmp) - s;
        if (sz < p) sz++;
        s[p] = v[i];
        r[i] = p;
    }
    ans = sz;

    //! solve
    sz = 0;
    for (i = 1; i <= n; i++) {
        if (i - 2 >= 1) {
            if (sz < l[i - 2]) sz++;
            s[l[i - 2]] = v[i - 2];
        }

        int p = upper_bound(s + 1, s + sz + 1, v[i] + 1) - s;
        ans = max(ans, p - 1 + r[i]);
    }

    ans = max(0, n - 1 - ans);
    printf("%d", ans);




    return 0;
}