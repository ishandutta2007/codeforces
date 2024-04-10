#include <bits/stdc++.h>
using namespace std;
const int N = 150005;

int n;
map<long long, set<int> > a;
set<long long> s;

int m;
long long b[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[x].insert(i);
        if (a[x].size() >= 2)
            s.insert(x);
    }
    while (!s.empty())
    {
        long long x = *s.begin();
        a[x].erase(a[x].begin());
        int i = *a[x].begin();
        a[x].erase(a[x].begin());
        if (a[x].size() < 2)
            s.erase(x);
        a[x * 2].insert(i);
        if (a[x * 2].size() >= 2)
            s.insert(x * 2);
    }
    for (int i = 1; i <= n; ++i)
        b[i] = -1;
    for (map<long long, set<int> >::iterator it = a.begin(); it != a.end(); ++it)
    {
        for (set<int>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1)
        {
            b[*it1] = it->first;
            ++m;
        }
    }
    cout << m << endl;
    for (int i = 1; i <= n; ++i)
        if (b[i] != -1)
            cout << b[i] << ' ';
    return 0;
}