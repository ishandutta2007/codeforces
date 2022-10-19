#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
struct ban
{
    double x, y;
};

int n;
ban a[N];

long long ans;

long long u;

void ave(long long x)
{
    ans += (x * (u - x));
}

map<double, set<double> > s;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;

    vector<double> v;

    int qq = 0;
    set<double> ss;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            double x1 = a[i].x;
            double y1 = a[i].y;
            double x2 = a[j].x;
            double y2 = a[j].y;
            if (x1 == x2)
            {
                if (ss.find(x1) == ss.end())
                {
                    ++qq;
                    ss.insert(x1);
                }
                continue;
            }
            double k = (y2 - y1) / (x2 - x1);
            double b = (-x1 * (y2 - y1) + y1 * (x2 - x1)) / (x2 - x1);
            if (s[k].find(b) == s[k].end())
            {
                v.push_back(k);
                s[k].insert(b);
            }
        }
    }
    sort(v.begin(), v.end());
    u = v.size() + qq;
    ave(qq);
    int q = 1;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] != v[i - 1])
        {
            ave(q);
            q = 1;
        }
        else
            ++q;
    }
    ave(q);
    cout << ans / 2 << endl;
    return 0;
}