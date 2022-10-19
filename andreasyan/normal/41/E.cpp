#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int n;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > ans;
    for (int i = 1; i <= (n / 2); ++i)
    {
        for (int j = (n / 2) + 1; j <= n; ++j)
        {
            ans.push_back(m_p(i, j));
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}