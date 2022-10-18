#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXC = 1000000;
int arr[500005], brr[500005], vis[500005], dis[500005], md[500005];
int sz[500005], bln[500005], where[500005], place[1000005], tp, n, m;

ll cal(ll day) {
    ll rt = 0;
    for (int i = 0; i < n; ++i) {
        if (md[i] == -1)
            continue;
        ll ti = day / n + ll(i < day % n);
        rt += ti / md[i];
        if (dis[i] < ti % md[i])
            ++rt;
    }
    return day - rt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll k, l = 0, r = 5e17;
    cin >> n >> m >> k;
    if (n < m) {
        for (int i = 0; i < n; ++i)
            cin >> brr[i];
        for (int i = 0; i < m; ++i)
            cin >> arr[i];
        swap(n, m);
    }
    else {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        for (int i = 0; i < m; ++i)
            cin >> brr[i];
    }
    memset(place, -1, sizeof place);
    for (int i = 0; i < m; ++i) {
        place[brr[i]] = i;
        if (!vis[i]) {
            for (int x = i; !vis[x]; x = (x + n) % m) {
                where[x] = sz[tp], bln[x] = tp;
                vis[x] = 1, ++sz[tp];
            }
            ++tp;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (place[arr[i]] == -1 || bln[place[arr[i]]] != bln[i % m]) {
            md[i] = -1;
            continue;
        }
        md[i] = sz[bln[i % m]];
        dis[i] = (where[place[arr[i]]] - where[i % m] + md[i]) % md[i];
    }
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (cal(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
}