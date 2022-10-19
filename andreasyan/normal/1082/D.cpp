#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 502;
struct ban
{
    int x;
    int d;
};
bool operator<(const ban& a, const ban& b)
{
    return a.d < b.d;
}

int n;
ban a[N];

int ans1;
vector<pair<int, int > > ans;
void kpc(int i, int j)
{
    a[i].d--;
    a[j].d--;
    ans.push_back(m_p(a[i].x, a[j].x));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i].x = i;
        cin >> a[i].d;
    }
    sort(a + 1, a + n + 1);
    int m;
    if (a[n].d == 1)
        m = n;
    else
        m = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i].d > 1)
        {
            kpc(i, i + 1);
            ++ans1;
        }
        else
        {
            m = i;
            break;
        }
    }
    int j = m + 1;
    for (int i = 1; i <= m; ++i)
    {
        if (i == 1)
        {
            if (a[m + 1].d)
            {
                kpc(i, m + 1);
                ++ans1;
                continue;
            }
        }
        if (i == 2)
        {
            if (a[n].d)
            {
                kpc(i, n);
                ++ans1;
                continue;
            }
        }
        while (1)
        {
            if (j == n + 1)
                break;
            if (a[j].d)
            {
                kpc(i, j);
                break;
            }
            else
                ++j;
        }
        if (a[i].d)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES " << ans1 << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}