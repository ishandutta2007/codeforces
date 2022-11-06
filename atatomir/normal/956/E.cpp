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

const int maxN = 10011;
const int inf = 1000000000;

ll n, i, j, l, r, H;
pair<ll, ll> Box[maxN];

ll ans[maxN], sol;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &l, &r);
    for (i = 1; i <= n; i++) scanf("%lld", &Box[i].second), H += Box[i].second, Box[i].second *= -1;
    for (i = 1; i <= n; i++) scanf("%lld", &Box[i].first);

    sort(Box + 1, Box + n + 1);
    for (i = 1; i <= n; i++) Box[i].second *= -1;

    l = H - l;
    r = H - r;
    swap(l, r);

    for (i = 0; i <= H; i++) ans[i] = -inf;
    ans[0] = 0;
    H = 0;

    for (i = 1; i <= n; i++) {
        for (j = H; j >= 0; j--) {
            if (ans[j] < 0) continue;
            ans[j + Box[i].second] = max(ans[j + Box[i].second], ans[j] + (l <= j + Box[i].second && j + Box[i].second <= r ?Box[i].first : 0));
            H = max(H, j + Box[i].second);
        }
    }

    for (i = 0; i <= H; i++) sol = max(sol, ans[i]);
    printf("%lld", sol);





    return 0;
}