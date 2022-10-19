#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
pair<pair<int, int>, int> a[N];
int ans[N];

bool so(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
{
    if (a.first.second < b.first.second)
        return true;
    if (a.first.second > b.first.second)
        return false;
    return a.first.first < b.first.first;
}

set<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a, a + n, so);
    for (int i = 0; i < n; ++i)
    {
        for (int j = a[i].first.first; j <= a[i].first.second; ++j)
        {
            if (s.find(j) == s.end())
            {
                s.insert(j);
                ans[a[i].second] = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}