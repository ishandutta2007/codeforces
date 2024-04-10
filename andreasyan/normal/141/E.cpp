#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;

int n, m;
vector<pair<int, int> > a;
vector<int> ai;
vector<pair<int, int> > b;
vector<int> bi;

int fi(int x, int p[])
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x], p);
}
void kpc(int x, int y, int p[])
{
    x = fi(x, p);
    y = fi(y, p);
    p[x] = y;
}

int p[N];
int pa[N];
int pb[N];

vector<int> ans;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        char z;
        cin >> x >> y >> z;
        if (z == 'S')
        {
            a.push_back(m_p(x, y));
            ai.push_back(i);
        }
        else
        {
            b.push_back(m_p(x, y));
            bi.push_back(i);
        }
    }

    if (n % 2 == 0)
    {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        if (fi(a[i].first, p) != fi(a[i].second, p))
            kpc(a[i].first, a[i].second, p);
    }

    for (int i = 1; i <= n; ++i)
        pa[i] = p[i];

    for (int i = 1; i <= n; ++i)
        pb[i] = i;
    int q = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        if (fi(b[i].first, p) != fi(b[i].second, p))
        {
            ++q;
            kpc(b[i].first, b[i].second, p);
            kpc(b[i].first, b[i].second, pb);
            ans.push_back(bi[i]);
        }
    }
    if (q > (n - 1) / 2)
    {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (fi(i, p) != fi(1, p))
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    for (int i = 0; i < b.size(); ++i)
    {
        if (q == (n - 1) / 2)
            break;
        if (fi(b[i].first, pa) == fi(b[i].second, pa) && fi(b[i].first, pb) != fi(b[i].second, pb))
        {
            kpc(b[i].first, b[i].second, pb);
            ++q;
            ans.push_back(bi[i]);
        }
    }
    if (q != (n - 1) / 2)
    {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        if (fi(a[i].first, pb) != fi(a[i].second, pb))
        {
            kpc(a[i].first, a[i].second, pb);
            ans.push_back(ai[i]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}