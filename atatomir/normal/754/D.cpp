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

#define maxN 300011

int n, k, i, last;
pair<ll, ll> intr[maxN];
vector< pair<ll, ll> > events;
ll l, r;

bool check(ll dist) {
    int i, j, cnt;

    events.clear();
    for (i = 1; i <= n; i++) {
        if (intr[i].second - intr[i].first + 1 < dist) continue;
        events.pb(mp(intr[i].first, +1));
        events.pb(mp(intr[i].second - dist + 2, -1));
    }

    if (events.size() / 2 < k) return false;

    sort(events.begin(), events.end());
    cnt = 0;

    for (i = 0; i < events.size(); i = j) {
        for (j = i; j < events.size(); j++) {
            if (events[i].first != events[j].first) break;
            cnt += events[j].second;
        }

        if (cnt >= k) {
            last = events[i].first;
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    events.reserve(2 * n);
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%lld%lld", &intr[i].first, &intr[i].second);

    ll ans = 0;
    for (ll step = (1LL << 32); step > 0; step >>= 1)
        if (check(ans + step))
            ans += step;

    printf("%lld\n", ans);

    if (ans == 0) {
        for (i = 1; i <= k; i++)
            printf("%d ", i);
    } else {
        check(ans);

        l = last; r = l + ans - 1;
        for (i = 1; i <= n && k > 0; i++) {
            if (intr[i].first <= l && r <= intr[i].second) {
                k--;
                printf("%d ", i);
            }
        }
    }

    return 0;
}