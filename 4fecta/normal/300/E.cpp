#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 1000005, MV = 10000005;

int n, k, a[MN], cnt[MV], vis[MV], id[MV], mp[MV];
vector<int> primes;

int count(int x, int d) { //logx(d)
    int ret = 0;
    while (x) ret += x /= d;
    return ret;
}

int find(int c, int d) {
    int lo = 1, hi = 1e14, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (count(mid, d) < c) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int check(int val) {
    for (int i = 0; i < primes.size(); i++) {
        int tmp = val, c = 0;
        while (tmp) tmp /= primes[i], c += tmp;
        if (c < cnt[i]) return false;
    }
    return true;
}

int32_t main() {
    boost();

    int lb = 1, ub = 0, mx = 0;
    for (int i = 2; i < MV; i++) {
        if (vis[i]) {id[i] = id[i - 1]; continue;}
        id[i] = primes.size();
        primes.push_back(i);
        for (int j = i; j < MV; j += i) vis[j] = 1, mp[j] = i;
    }

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i]; ub += a[i]; mx = max(mx, a[i]);
        cnt[a[i]]++;
        /*for (int j = 0; j < min((ll) primes.size(), 200ll); j++) cnt[primes[j]] += count(a[i], primes[j]);
        for (int j = id[a[i]]; j >= max(200ll, id[a[i]] - 200); j--) cnt[primes[j]] += count(a[i], primes[j]);*/
    }
    for (int i = mx; i > 1; i--) cnt[i] += cnt[i + 1];
    for (int i = mx; i > 1; i--) {
        int val = mp[i];
        if (val != i) cnt[val] += cnt[i];
        cnt[i / val] += cnt[i];
    }
    for (int i = 0; i < primes.size(); i++) cnt[i] = cnt[primes[i]];
    while (lb < ub) {
        int mid = (lb + ub) >> 1;
        if (check(mid)) ub = mid;
        else lb = mid + 1;
    }
    printf("%lld\n", lb);

    return 0;
}