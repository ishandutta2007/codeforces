#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

const int maxn = 250007, maxm = 10000007;
const ll inf = 2e18;

#define left left_
#define right right_
ll cost[maxm], height[maxm], left[maxm], right[maxm], dp[maxm], tmp[maxm];
int n, m, q, bleft[maxn], bsize[maxn], bcost[maxn], bheight[maxn], ptr = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int id = 1; id <= n; ++id) {
        int k; cin >> k;
        bleft[id] = ptr, bsize[id] = k;
        for (int i = ptr; i < ptr + k; ++i) cin >> bheight[i];
        for (int i = ptr; i < ptr + k; ++i) cin >> bcost[i];
        ptr += k;
    }

    ptr = 1;
    cin >> q;
    while (q--) {
        int id; ll mul; cin >> id >> mul;
        for (int i = 0, j = bleft[id]; i < bsize[id]; ++i, ++ptr, ++j) {
            height[ptr] = bheight[j];
            cost[ptr] = bcost[j] * mul;
        }
    }

    for (int i = m; i >= 1; --i) {
    	for (right[i] = i+1; right[i] <= m && right[i] - height[i] < i; right[i] = right[right[i]]);
    }

	for (int i = 1; i <= m; ++i) dp[i] = inf;
    for (int i = 1; i <= m; ++i) {
        for (left[i] = i-1, tmp[i] = dp[i-1]; left[i] > 0 && left[i] + height[i] > i; tmp[i] = min(tmp[i], tmp[left[i]]), left[i] = left[left[i]]);
        dp[i] = min(dp[i], tmp[i] + cost[i]);
        dp[right[i] - 1] = min(dp[right[i] - 1], dp[i-1] + cost[i]);
    }

    cout << dp[m] << endl;
}