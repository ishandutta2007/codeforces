#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define inf 1000000011

int n, i, bit;
int val[maxN];
int last[33];
int l[maxN], r[maxN];
stack< pair<int, int> > S;
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &val[i]);

    //! from left to right
    for (i = 0; i <= 30; i++) last[i] = 0;
    while (!S.empty()) S.pop();
    S.push(mp(inf, 0));

    for (i = 1; i <= n; i++) {
        while (S.top().first < val[i]) S.pop();
        l[i] = S.top().second;
        S.push(mp(val[i], i));

        for (bit = 0; bit <= 30; bit++) {
            if (val[i] & (1 << bit)) {
                last[bit] = i;
            } else {
                l[i] = max(l[i], last[bit]);
            }
        }
    }

    //! from right to right
    for (i = 0; i <= 30; i++) last[i] = n + 1;
    while (!S.empty()) S.pop();
    S.push(mp(inf, n + 1));

    for (i = n; i >= 1; i--) {
        while (S.top().first <= val[i]) S.pop();
        r[i] = S.top().second;
        S.push(mp(val[i], i));

        for (bit = 0; bit <= 30; bit++) {
            if (val[i] & (1 << bit)) {
                last[bit] = i;
            } else {
                r[i] = min(r[i], last[bit]);
            }
        }
    }

    //! conclusions
    ans = (1LL * n * (n - 1)) / 2LL;
    for (i = 1; i <= n; i++)
        ans -= 1LL * (i - l[i]) * (r[i] - i) - 1LL;

    printf("%lld", ans);



    return 0;
}