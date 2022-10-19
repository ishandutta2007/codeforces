#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n, m;
vector<pair<int, int> > v;

bool stg(int x)
{
    vector<pair<int, int> > vv;
    for (int i = 0; i < v.size(); ++i)
    {
        vv.push_back(m_p(min((v[i].first + x) % n, (v[i].second + x) % n), max((v[i].first + x) % n, (v[i].second + x) % n)));
    }
    sort(vv.begin(), vv.end());
    return v == vv;
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        v.push_back(m_p(min(x, y), max(x, y)));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i)
    {
        if (n % i == 0 && stg(i))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}