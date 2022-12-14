#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> t(m);
    vector<int> r(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> t[i] >> r[i];
        --t[i];
    }
    
    vector<pair<int, int>> s(m + 1);
    s.back() = {INT_MIN, m};

    for(int i = m - 1; i >= 0; --i)
    {
        s[i] = max(s[i + 1], make_pair(r[i], i));
    }
    
    int p = 0;
    vector<pair<int, int>> q;
    while(p < m)
    {
        q.push_back({s[p].first, t[s[p].second]});
        p = s[p].second + 1;
    }
    q.push_back({0, 228});
    
    int ll = 0, rr = n - 1;
    vector<int> res;
    for(; q.front().first <= rr; --rr)
    {
        cerr << a[rr] << "!" << endl;
        res.push_back(a[rr]);
    }
    
    sort(a.begin(), a.begin() + q.front().first);

    for(int i = 0; i + 1 < q.size(); ++i)
    {
        int cnt = q[i].first - q[i + 1].first;
        if(q[i].second == 0)
        {
            for(int j = 0; j < cnt; ++j, --rr)
            {
                res.push_back(a[rr]);
            }
        }
        else
        {
            for(int j = 0; j < cnt; ++j, ++ll)
            {
                res.push_back(a[ll]);
            }
        }
    }
    reverse(res.begin(), res.end());
    for(int i : res)
        cout << i << " ";
    cout << endl;
}