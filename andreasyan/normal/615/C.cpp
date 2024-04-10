#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2103;

int z;
map<char, int> b[N * N];
pair<int, int> s[N * N];

int n, m;
char a[N], f[N];

int main()
{
    cin >> a >> f;
    n = strlen(a);
    m = strlen(f);

    for (int i = 0; i < n; ++i)
    {
        int pos = 0;
        for (int j = i; j < n; ++j)
        {
            if (b[pos].find(a[j]) == b[pos].end())
                b[pos][a[j]] = ++z;
            pos = b[pos][a[j]];
            s[pos] = m_p(i, j);
        }

        pos = 0;
        for (int j = i; j >= 0; --j)
        {
            if (b[pos].find(a[j])  == b[pos].end())
                b[pos][a[j]] = ++z;
            pos = b[pos][a[j]];
            s[pos] = m_p(i, j);
        }
    }

    int i = 0;
    vector<pair<int, int> > ans;
    while (1)
    {
        if (i == m)
            break;
        int pos = 0;
        if (b[pos].find(f[i]) == b[pos].end())
        {
            cout << -1 << endl;
            return 0;
        }
        while (b[pos].find(f[i]) != b[pos].end())
        {
            pos = b[pos][f[i]];
            ++i;
            if (i == m)
                break;
        }
        ans.push_back(s[pos]);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    return 0;
}