#include<bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

#define left ada
#define right mant
int left[4 * maxn], right[4 * maxn], inn[4 * maxn], sum[4 * maxn];


const int inf = 1e16;

void upd(int p, int c, int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        left[v] = right[v] = inn[v] = sum[v] = c;
        return;
    }
    int m = (l + r) / 2;
    if(p < m)
        upd(p, c, 2 * v, l, m);
    else
        upd(p, c, 2 * v + 1, m, r);
    left[v] = max(left[2 * v], sum[2 * v] + left[2 * v + 1]);
    right[v] = max(right[2 * v + 1], sum[2 * v + 1] + right[2 * v]);
    inn[v] = max({inn[2 * v], inn[2 * v + 1], right[2 * v] + left[2 * v + 1]});
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    sum[v] = max(sum[v], -inf);
    left[v] = max(left[v], -inf);
    right[v] = max(right[v], -inf);
    inn[v] = max(inn[v], -inf);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        upd(i, a[i]);
    }
    int p[n];
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        upd(p[i] - 1, -inf);
        cout << inn[1] << "\n";
    }
    return 0;
}