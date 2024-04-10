#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

using namespace std::rel_ops;

struct q
{
    nagai a, b;
    int ind;
    q(nagai a, nagai b)
    {
        b = -b;
        if (a < 0)
            a = -a, b = -b;
        this->a = a;
        this->b = b;
    }
    q() : a(0), b(0)
    {}
    bool operator <(q o) const
    {
        return a * o.b < b * o.a;
    }
    bool operator ==(q o) const
    {
        return a * o.b == b * o.a;
    }
};

nagai ans = 0;

vector<q> b;

const int N = 1 << 18;
nagai t[N * 2];

nagai get(int l, int r)
{
    l += N;
    r += N;
    nagai ans = 0;
    while (l < r)
    {
        if (l & 1)
            ans += t[l++];
        if (r & 1)
            ans += t[--r];
        l >>= 1, r >>= 1;
    }
    return ans;
}

void add(int x, nagai y)
{
    x += N;
    t[x] += y;
    while (x)
        t[x >> 1] = t[x] + t[x ^ 1], x >>= 1;
}

ostream& operator <<(ostream& a, q b)
{
    return a << b.a / (double)b.b;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> v[i];
    vector<q> a;
    for (int i = 0; i < n; ++i)
    {
        a.push_back(q(x[i], v[i] + w));
        b.push_back(q(x[i], v[i] - w));
    }
    vector<q> as;
    for (auto& x : a)
        as.push_back(x);
    sort(as.begin(), as.end());
    as.resize(unique(as.begin(), as.end()) - as.begin());
    for (int i = 0; i < n; ++i)
    {
        b[i].ind = lower_bound(as.begin(), as.end(), a[i]) - as.begin();
    }
    sort(b.begin(), b.end());
    int ptr = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i < ptr)
            continue;
        vector<q> v;
        while (ptr < n && b[ptr] == b[i])
            v.push_back(b[ptr++]);
        for (auto& x : v)
        {
            ans += get(x.ind, x.ind + 1);
            add(x.ind, 1);
        }
        for (auto& x : v)
            ans += get(x.ind + 1, N);
    }
    cout << ans << '\n';
}