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

#define maxN 100011
#define dleft (p1)
#define dright (n - p2 + 1)

int n, m, i, p1, p2, odd, same;
int v[maxN];
int cnt[maxN];
ll ans;

int get_pref(int n) {
    int i;

    memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= m; i++) cnt[v[i]]++;

    for (i = 1; 2 * i <= n; i++) {
        cnt[v[i]] -= 2;
        if (cnt[v[i]] < 0) break;
    }

    if (2 * i > n) {
        if (n % 2 == 1 && cnt[v[(n + 1) / 2]] == 0) return i - 1;
        for (; i < n && v[i] == v[n - i + 1]; i++);
    }
    return i - 1;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]), cnt[v[i]]++;
    for (i = 1; i <= n; i++) odd += (cnt[i] & 1);
    if (odd > 1) {
        printf("0");
        return 0;
    }

    if (n == 1) {
        printf("1");
        return 0;
    }

    for (same = 1; 2 * same <= n && v[same] == v[n - same + 1]; same++);
    same--;

    if (2 * same + 1 >= n) {
        ans = (1LL * n * (n + 1)) / 2;
        printf("%lld", ans);
        return 0;
    }

    for (i = same + 1; i <= n - same; i++) v[i - same] = v[i];
    m = n - 2 * same;
    ans = same * same;

    int pref = get_pref(m);
    reverse(v + 1, v + m + 1);
    int suf = get_pref(m);

    ans += (same + 1) * (pref + suf + 2);
    ans--;
    printf("%lld", ans);



    return 0;
}