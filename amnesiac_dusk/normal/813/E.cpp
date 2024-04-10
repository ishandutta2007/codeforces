#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5;
int root[maxn], L[16 * maxn], R[16 * maxn], sum[16 * maxn];
int rt = 1, sz = 1;

int copy(int v, int &u)
{
    L[sz] = L[v];
    R[sz] = R[v];
    sum[sz] = sum[v];
    return u = sz++;
}

void make_root()
{
    copy(root[rt - 1], root[rt]);
    rt++;
}

void add(int pos, int x, int v = root[rt - 1], int l = 0, int r = maxn)
{
	sum[v] += x;
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    if(pos < m)
        add(pos, x, copy(L[v], L[v]), l, m);
    else
        add(pos, x, copy(R[v], R[v]), m, r);
}

int get(int a, int b, int v, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return sum[v];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return get(a, b, L[v], l, m) + get(a, b, R[v], m, r);
}
queue<int> val[100001];
int main()
 {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n>>k;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        make_root();
        if(val[t].size()==k)
        {
        	add(val[t].front(), -1);
        	val[t].pop();
        }
        add(i, 1);
        val[t].push(i);
    }
    int q, l, r;
    cin >> q;
    int last=0;
    while(q--)
    {
        cin >> l >> r;
        l=(l+last)%n+1;
        r=(r+last)%n+1;
        if(l>r)
        	swap(l,r);
        last=get(l, r + 1, root[r]);
        cout <<last  << "\n";
    }
    return 0;
 }