#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int m = 1000000;

int n;

bool c[m];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        c[x - 1] = true;
    }
    vector<int> ans;
    vector<pair<int, int> > gg;
    int q = 0;
    for (int i = 0; i < m; ++i)
    {
        if (c[i])
        {
            if (!c[m - i - 1])
                ans.push_back(m - i - 1);
            else
                ++q;
        }
        else
        {
            if (!c[m - i - 1])
                gg.push_back(m_p(i, m - i - 1));
        }
    }
    q /= 2;
    for (int i = 0; i < q; ++i)
    {
        ans.push_back(gg[i].first);
        ans.push_back(gg[i].second);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << ' ';
    cout << endl;
    return 0;
}