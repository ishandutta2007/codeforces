#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n, m;
int t[N], x[N];

long long ans[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> x[i];
    int ii = 0;
    long long tt = 0;
    int xx = 0;
    while (1)
    {
        tt += xx;
        xx = 0;

        if (ii >= n)
            break;

        vector<pair<int, int> > v;
        for (int i = ii; i < min(n, ii + m); ++i)
        {
            tt = max(tt, (long long)t[i]);
            v.push_back(m_p(x[i], i));
        }
        ii += m;
        sort(v.begin(), v.end());

        int q = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!i || v[i].first == v[i - 1].first)
                ++q;
            else
            {
                tt += (v[i - 1].first - xx);
                xx = v[i - 1].first;
                for (int j = i - q; j < i; ++j)
                {
                    ans[v[j].second] = tt;
                }
                tt += (q / 2 + 1);
                q = 1;
            }
        }
        {
            tt += (v.back().first - xx);
            xx = v.back().first;
            for (int j = v.size() - q; j < v.size(); ++j)
            {
                ans[v[j].second] = tt;
            }
            tt += (q / 2 + 1);
            q = 1;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}