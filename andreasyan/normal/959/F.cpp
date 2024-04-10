#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1000000007;
struct ban
{
    int i;
    int l, x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.l < b.l;
}

int n, q;
int a[N];
ban b[N];

set<int> c;
int ans = 1;

void ad(int x)
{
    if (c.find(x) != c.end())
        ans = (ans * 2) % M;
    else
    {
        vector<int> v;
        for (set<int>::iterator it = c.begin(); it != c.end(); ++it)
            v.push_back(*it ^ x);
        for (int i = 0; i < v.size(); ++i)
            c.insert(v[i]);
    }
}

int yans[N];

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i)
    {
        b[i].i = i;
        cin >> b[i].l >> b[i].x;
    }
    sort(b, b + q);
    c.insert(0);
    int i = 1;
    for (int j = 0; j < q; ++j)
    {
        while (b[j].l >= i)
        {
            ad(a[i]);
            ++i;
        }
        if (c.find(b[j].x) != c.end())
            yans[b[j].i] = ans;
    }
    for (int i = 0; i < q; ++i)
        cout << yans[i] << endl;
    return 0;
}