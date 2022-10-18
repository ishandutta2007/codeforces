#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5, sigma = 26;

int pl[4 * maxn][sigma], sm[4 * maxn][sigma];
int tp[4 * maxn][sigma];

void push(int v, int l, int r, int c)
{
    if(tp[v][c] == 0)
    {
        if(pl[v][c] == 0)
            return;
        sm[v][c] += (r - l) * pl[v][c];
        if(r - l == 1)
        {
            pl[v][c] = 0;
            return;
        }
        int m = (l + r) >> 1;
        if(tp[v << 1][c] == 1)
            push(v << 1, l, m, c);
        if(tp[(v << 1) + 1][c] == 1)
            push((v << 1) + 1, m, r, c);
        pl[v << 1][c] += pl[v][c];
        pl[(v << 1) + 1][c] += pl[v][c];
        pl[v][c] = 0;
    }
    else
    {
        tp[v][c] = 0;
        sm[v][c] = 0;
        pl[v][c] = 0;
        if(r - l == 1)
            return;
        tp[v << 1][c] = 1;
        tp[(v << 1) + 1][c] = 1;
    }
}

void add(int a, int b, int c, int v = 1, int l = 0, int r = maxn)
{
    push(v, l, r, c);
    if(a <= l && r <= b)
    {
        pl[v][c] = 1;
        tp[v][c] = 0;
        push(v, l, r, c);
        return;
    }
    if(r <= a || b <= l)
        return;
    int m = (l + r) >> 1;
    add(a, b, c, v << 1, l, m);
    add(a, b, c, (v << 1) + 1, m, r);
    sm[v][c] = sm[v << 1][c] + sm[(v << 1) + 1][c];
}

int pop(int a, int b, int c, int v = 1, int l = 0, int r = maxn)
{
    push(v, l, r, c);
    if(a <= l && r <= b)
    {
        int R = sm[v][c];
        tp[v][c] = 1;
        push(v, l, r, c);
        return R;
    }
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) >> 1;
    int ret = pop(a, b, c, v << 1, l, m) + pop(a, b, c, (v << 1) + 1, m, r);
    sm[v][c] = sm[v << 1][c] + sm[(v << 1) + 1][c];
    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
        add(i, i + 1, s[i] - 'a');
    while(q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        int tl = l;
        for(int z = 0; z < sigma; z++)
        {
            int c = k ? z : sigma - z - 1;
            int cnt = pop(l, r, c);
            add(tl, tl + cnt, c);
            tl += cnt;
        }
    }
    for(int i = 0; i < n; i++)
        for(int c = 0; c < sigma; c++)
            if(pop(i, i + 1, c) == 1)
            {
                cout << char(c + 'a');
                break;
            }
    cout << endl;
    return 0;
}