#include <bits/stdc++.h>

using namespace std;

const int maxn = 100007, inf = maxn;
int num[4 * maxn];

void init()
{
    memset(num, -1, sizeof(num));
}

void change(int pos, int c, int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        num[v] = c;
        return;
    }
    int m = (l + r) / 2;
    if(pos < m)
        change(pos, c, 2 * v, l, m);
    else
        change(pos, c, 2 * v + 1, m, r);
    num[v] = min(num[2 * v], num[2 * v + 1]);
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return num[v];
    if(r <= a || b <= l)
        return inf;
    int m = (l + r) / 2;
    return min(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<pair<int, int>> lad(k);
    for(int i = 0; i < k; i++)
        cin >> lad[i].first >> lad[i].second;
    int Q[q][4];
    for(int i = 0; i < q; i++)
        cin >> Q[i][0] >> Q[i][1] >> Q[i][2] >> Q[i][3];
    int ans[q];
    memset(ans, 0, sizeof(ans));
    for(int z = 0; z < 2; z++)
    {
        init();
        vector<int> LAD[n + 1];;
        for(int i = 0; i < k; i++)
            LAD[lad[i].first].push_back(lad[i].second);
        vector<int> que[n + 1];
        for(int i = 0; i < q; i++)
            que[Q[i][2]].push_back(i);
        for(int i = 1; i <= n; i++)
        {
            for(auto it: LAD[i])
                change(it, i);
            for(auto it: que[i])
                ans[it] |= get(Q[it][1], Q[it][3] + 1) >= Q[it][0];
        }

        swap(n, m);
        for(int i = 0; i < k; i++)
            swap(lad[i].first, lad[i].second);
        for(int i = 0; i < q; i++)
            swap(Q[i][0], Q[i][1]),
            swap(Q[i][2], Q[i][3]);
    }
    for(int i = 0; i < q; i++)
        if(ans[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    return 0;
}