#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1 << 18, inf = 1e18;
int d[4 * maxn], h[4 * maxn];
int max_xd[8 * maxn], max_yd[8 * maxn], bst[8 * maxn];

void build(int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        max_xd[v] = 2 * h[l] - d[l];
        max_yd[v] = 2 * h[l] + d[l];
        bst[v] = -inf;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    max_xd[v] = max(max_xd[2 * v], max_xd[2 * v + 1]);
    max_yd[v] = max(max_yd[2 * v], max_yd[2 * v + 1]);
    bst[v] = max(max_xd[2 * v] + max_yd[2 * v + 1], max(bst[2 * v], bst[2 * v + 1]));
}

tuple<int, int, int> get(int a, int b, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return make_tuple(max_xd[v], max_yd[v], bst[v]);
    if(r <= a || b <= l)
        return make_tuple(-inf, -inf, -inf);
    int m = (l + r) / 2;
    auto A = get(a, b, 2 * v, l, m);
    auto B = get(a, b, 2 * v + 1, m, r);
    auto C = A;
    get<0>(C) = max(get<0>(A), get<0>(B));
    get<1>(C) = max(get<1>(A), get<1>(B));
    get<2>(C) = max(get<2>(A), get<2>(B));
    get<2>(C) = max(get<2>(C), get<0>(A) + get<1>(B));
    //cout << l << ' ' << r << ' ' << endl;
    //cout << get<0>(C) << ' ' << get<1>(C) << ' ' << get<2>(C) << "\n";
    return C;
}

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++)
        h[i + n] = h[i];
    for(int i = 1; i <= n; i++)
        d[i + n] = d[i];
    for(int i = 1; i <= 2 * n; i++)
        d[i] += d[i - 1];
    build();
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        if(a <= b)
        {
            int t = a;
            a = b;
            b = t + n - 1;
        }
        else
        {
            int t = a;
            a = b + n;
            b = t + n - 1;
        }
        if(a == b)
            b += n - 1;
        cout << max(0LL, get<2>(get(a, b))) << "\n";
    }
}
/*
1 2 3 4  1 2 3 4
*/