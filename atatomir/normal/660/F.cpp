#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define inf (1LL << 60)

int n, i;
ll a[maxN], sum[maxN];
ll ans;

vector< pair<ll, ll> > lines, low;

ll get_intersection(int id1, int id2) {
    auto l1 = lines[id1];
    auto l2 = lines[id2];

    return (l1.second - l2.second + l2.first - l1.first - 1) / (l2.first - l1.first);
}

void lower() {
    int i;
    int pos;
    ll last;

    // remove parallel lines
    sort(lines.begin(), lines.end());

    pos = 0;
    for (i = 1; i < lines.size(); i++) {
        if (lines[i].first == lines[i - 1].first)
            lines[pos] = lines[i];
        else
            lines[++pos] = lines[i];
    }

    lines.resize(pos + 1);

    // compute ...
    low = {mp(-inf, 0LL)};

    for (i = 1; i < lines.size(); i++) {
        while (!low.empty()) {
            last = get_intersection(low.back().second, i);
            if (last > low.back().first) break;
            low.pop_back();
        }

        low.pb(mp(last, i));
    }

}

void solve(int l, int r) {
    if (l == r) {
        ans = max(ans, a[l]);
        return;
    }

    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);

    // get the lines
    int i;
    ll act = 0;

    lines.clear();
    for (i = mid + 1; i <= r; i++) {
        act += 1LL * (i - mid) * a[i];
        lines.pb(mp(sum[i] - sum[mid], act));
    }

    lower();

    // update answer
    reverse(low.begin(), low.end());


    act = 0;
    for (i = mid; i >= l; i--) {
        act += sum[mid] - sum[i - 1];

        while (low.size() > 1){
            if (low[low.size() - 2].first > mid - i + 1)
                break;
            low.pop_back();
        }
        auto l = lines[low.back().second];

        ans = max(ans, act + l.first * (mid - i + 1) + l.second);
    }

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }


    solve(1, n);
    printf("%lld", ans);


    return 0;
}