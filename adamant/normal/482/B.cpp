#include <bits/stdc++.h>

using namespace std;

const int MPOW = 18, MAXN = 1 << MPOW;
int AND[MAXN << 1];

void push_or(int a, int b, int q, int v = 1, int l = 0, int r = MAXN)
{
    if(a <= l && r <= b)
    {
        AND[v] |= q;
        return;
    }
    if(r <= a || b <= l)
        return;
    int m = (l + r) / 2;
    push_or(a, b, q, 2 * v    , l, m);
    push_or(a, b, q, 2 * v + 1, m, r);
    AND[v] |= AND[2 * v] & AND[2 * v + 1];
}

int check_and(int a, int b, int v = 1, int l = 0, int r = MAXN)
{
    if(a <= l && r <= b)
        return AND[v];
    if(r <= a || b <= l)
        return (1 << 30) - 1;
    int m = (l + r) / 2;
    return AND[v] | (check_and(a, b, 2 * v, l, m) & check_and(a, b, 2 * v + 1, m, r));
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> Q;
    while(m--)
    {
        int l, r, q;
        cin >> l >> r >> q;
        l--;
        push_or(l, r, q);
        Q.push_back({{l, r}, q});
    }
    for(auto it: Q)
        if(check_and(it.first.first, it.first.second) != it.second)
        {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << check_and(i, i + 1) << ' ';
    return 0;
}