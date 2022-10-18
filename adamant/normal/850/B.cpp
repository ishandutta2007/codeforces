#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e6 + 42, inf = 1e17;
int pr[maxn];


signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	int k = x / y;
	int a[n];
	for(auto &it: a)
        cin >> it;
    sort(a, a + n);
    int sm[n + 1] = {0};
    partial_sum(a, a + n, sm + 1);
    int ans = inf;
    for(int i = 2; i < maxn; i++)
    {
        if(pr[i])
            continue;
        int cur = 0;
        for(int j = i; j < maxn; j += i)
        {
            pr[j] = 1;
            auto it = upper_bound(a, a + n, j - i);
            auto jt = lower_bound(a, a + n, j);
            auto mt = lower_bound(a, a + n, max(j - i + 1, j - k));
            // [it; mt) U [mt; jt)
            int will_add = jt - mt;
            int will_del = mt - it;
            cur += will_del * x + (j * will_add - (sm[jt - a] - sm[mt - a])) * y;
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}