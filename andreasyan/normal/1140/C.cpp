#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct ban
{
    int t, b;
    ban()
    {
        t = b = 0;
    }
    ban(int t, int b)
    {
        this->t = t;
        this->b = b;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.b > b.b;
}


int n, k;
ban a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].t >> a[i].b;
    sort(a + 1, a + n + 1);
    multiset<int> s;
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s.size() < k)
        {
            s.insert(a[i].t);
            sum += a[i].t;
        }
        else
        {
            if (a[i].t > *(s.begin()))
            {
                sum -= (*s.begin());
                s.erase(s.begin());
                s.insert(a[i].t);
                sum += a[i].t;
            }
        }
        ans = max(ans, sum * a[i].b);
    }
    cout << ans << endl;
    return 0;
}