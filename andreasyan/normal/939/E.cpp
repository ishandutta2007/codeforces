#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<long long> p;

long double qry()
{
    if (v.size() == 1)
        return v.back();
    int l = 1, r = v.size() - 2;
    while ((r - l) > 4)
    {
        int m = (l + r) / 2;
        if ((p[m] + v.back()) * (m + 1) < (p[m - 1] + v.back()) * (m + 2))
            l = m;
        else
            r = m;
    }
    for (int m = r; m >= l; --m)
    {
        if ((p[m] + v.back()) * (m + 1) < (p[m - 1] + v.back()) * (m + 2))
        {
            return 1.0 * (p[m] + v.back()) / (m + 2);
        }
    }
    return 1.0 * (p[0] + v.back()) / 2;
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    int q;
    cin >> q;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x;
            cin >> x;
            v.push_back(x);
            if (p.empty())
                p.push_back(x);
            else
                p.push_back(p.back() + x);
        }
        else
        {
            cout << v.back() - qry() << endl;
        }
    }
    return 0;
}