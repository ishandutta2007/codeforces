#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

struct aib {
    ll n;
    ll data[maxN];

    ll zrs(ll x) {
        return (x ^ (x - 1)) & x;
    }

    ll sum(ll pos) {
        ll ans = 0;
        while (pos > 0) {
            ans += data[pos];
            pos -= zrs(pos);
        }
        return ans;
    }

    void add(ll pos, ll val) {
        while (pos <= n) {
            data[pos] += val;
            pos += zrs(pos);
        }
    }

    ll cb(ll x) {
        ll ans = 0;

        for (ll step = (1 << 20); step > 0; step >>= 1)
            if (ans + step <= n)
                if (data[ans + step] <= x)
                    {ans += step; x -= data[ans];}

        return ans;

    }
};

ll n, T, i, t, a, wh[maxN];
pair< pair<ll, ll>, ll> ord[maxN];
vector< pair<ll, ll> > tm[maxN];
priority_queue< pair<ll, ll> > H;
ll cnt_H, sum_H;
aib cnt, sum;
pair<ll, ll> ans;

vector< pair<ll, ll> > v1, v2;

bool check(int val) {
    if (cnt_H >= val) return true;
    int need = val - cnt_H;

    int pos = cnt.cb(need - 1) + 1;
    if (pos > n) return false;
    if (sum_H + sum.sum(pos) <= T) return true;
    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &T);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &a, &t);
        ord[i] = mp(mp(t, a), i);
        tm[a].pb(mp(t, i));
    }

    sort(ord + 1, ord + n + 1);
    for (i = 1; i <= n; i++)
        wh[ord[i].second] = i;

    cnt.n = sum.n = n;

    for (i = 1; i <= n; i++) {
        cnt.add(i, 1);
        sum.add(i, ord[i].first.first);
    }

    for (i = n; i >= 1; i--) {
        for (auto e : tm[i]) {
            cnt.add(wh[e.second], -1);
            sum.add(wh[e.second], -e.first);
            H.push(e);
            cnt_H++;
            sum_H += e.first;
        }

        while (sum_H > T || cnt_H > i) {
            cnt_H--;
            sum_H -= H.top().first;
            H.pop();
        }

        /*while (!H.empty()) {
            if (check(i)) break;
            cnt_H--;
            sum_H -= H.top().first;
            H.pop();
        }*/

        //if (check(i))
            ans = max(ans, mp(min(cnt_H, i), i - 1));
    }

    for (i = 1; i <= ans.second; i++)
        for (auto e : tm[i])
            v1.pb(e);

    for (i = ans.second + 1; i <= n; i++)
        for (auto e : tm[i])
            v2.pb(e);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    //v1.resize(ans.first);
    v2.resize(ans.first);

    printf("%lld\n%lld\n", ans.first, ans.first);
    //for (auto e : v1) printf("%lld ", e.second);
    for (auto e : v2) printf("%lld ", e.second);


    return 0;
}