#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long M = 1000000007;
struct ban
{
    long long l, r;
    ban()
    {
        l = r = 0;
    }
    ban(long long l, long long r)
    {
        this->l = l;
        this->r = r;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.l < b.l;
}

int n;
long long y, x;
ban a[N];

int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1);

    long long ans = 0;
    multiset<long long> s;
    for (int i = 1; i <= n; ++i)
    {
        multiset<long long>::iterator it = s.lower_bound(a[i].l);
        if (!s.empty())
            --it;
        if (it == s.end())
        {
            ans = (ans + x + (a[i].r - a[i].l) * y) % M;
            s.insert(a[i].r);
        }
        else
        {
            int rr = *it;
            if (rr >= a[i].l)
            {
                ans = (ans + x + (a[i].r - a[i].l) * y) % M;
                s.insert(a[i].r);
                continue;
            }
            if (x + (a[i].r - a[i].l) * y <= (a[i].r - rr) * y)
            {
                ans = (ans + x + (a[i].r - a[i].l) * y) % M;
                s.insert(a[i].r);
            }
            else
            {
                ans = (ans + (a[i].r - rr) * y) % M;
                s.insert(a[i].r);
                s.erase(it);
            }
        }
    }
    cout << ans << endl;
    return 0;
}