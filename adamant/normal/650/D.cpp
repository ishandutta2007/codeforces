#include <bits/stdc++.h>

using namespace std;

const int maxn = 8e5;

int mx[2][4 * maxn];
int bst[4 * maxn];

int get(int t, int a, int b, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return mx[t][v];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return max(get(t, a, b, 2 * v, l, m), get(t, a, b, 2 * v + 1, m, r));
}

void make(int t, int p, int c, int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        mx[t][v] = c;
        return;
    }
    int m = (l + r) / 2;
    if(p < m)
        make(t, p, c, 2 * v, l, m);
    else
        make(t, p, c, 2 * v + 1, m, r);
    bst[v] = max(mx[0][2 * v] + mx[1][2 * v + 1], max(bst[2 * v], bst[2 * v + 1]));
    mx[t][v] = max(mx[t][2 * v], mx[t][2 * v + 1]);
}

map<int, int> hasher;
int hsh(int x)
{
    if(hasher[x] == 0)
        hasher[x] = hasher.size();
    return hasher[x];
}

signed main()
{
    //cout << (sizeof(bst) + sizeof(mx) >> 20) << endl;
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int nums[n + m];
    int h[n];
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
        nums[i] = h[i];
    }
    int a[m], b[m];
    for(int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        nums[n + i] = b[i];
    }
    sort(nums, nums + n + m);
    for(int i = 0; i < n + m; i++)
        hsh(nums[i]);
    for(int i = 0; i < n; i++)
        h[i] = hsh(h[i]);
    for(int i = 0; i < m; i++)
        b[i] = hsh(b[i]);
    vector<int> Q[n];
    for(int i = 0; i < m; i++)
        Q[a[i] - 1].push_back(i);
    int old[n];
    for(int i = n - 1; i > 0; i--)
    {
        int cur = get(1, h[i], h[i] + 1);
        int nw = 1 + get(1, h[i] + 1, maxn);
        old[i] = cur;
        make(1, h[i], nw);
        //cout << cur << ' ' << nw << ' ' << bst[1] << endl;
    }
    int ans[m];
    for(int i = 0; i < n; i++)
    {
        int cbs = bst[1];
        for(auto it: Q[i])
        {
            //cout << cbs << ' ' << get(0, 0, b[it]) << ' ' << get(1, b[it] + 1, maxn) << endl;
            ans[it] = max(cbs, 1 + get(0, 0, b[it]) + get(1, b[it] + 1, maxn));
        }
        if(i + 1 < n)
            make(1, h[i + 1], old[i + 1]);
        make(0, h[i], 1 + get(0, 0, h[i]));
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}