#include <bits/stdc++.h>
using namespace std;
const int N = 50004;

int n;
int a[N];

set<int> s, ss;

map<int, vector<int> > v;

void solv(int x)
{
    if (ss.find(x) == ss.end())
        return;
    solv(x * 2);
    solv(x * 2 + 1);
    v[x].push_back(x);
    if (s.find(x) == s.end())
    {
        if (v[x * 2 + 1].empty())
        {
            v[x * 2].pop_back();
        }
        else if (v[x * 2].empty())
        {
            v[x * 2 + 1].pop_back();
        }
        else
        {
            if (v[x * 2].back() > v[x * 2 + 1].back())
                v[x * 2].pop_back();
            else
                v[x * 2 + 1].pop_back();
        }
    }
    int j = 0;
    for (int i = 0; i < v[x * 2].size(); ++i)
    {
        while (j != v[x * 2 + 1].size() && v[x * 2 + 1][j] < v[x * 2][i])
            v[x].push_back(v[x * 2 + 1][j++]);
        v[x].push_back(v[x * 2][i]);
    }
    while (j != v[x * 2 + 1].size())
        v[x].push_back(v[x * 2 + 1][j++]);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);
        while (a[i])
        {
            ss.insert(a[i]);
            a[i] /= 2;
        }
    }
    solv(1);
    for (int i = 0; i < v[1].size(); ++i)
        cout << v[1][i] << ' ';
    cout << endl;
    return 0;
}