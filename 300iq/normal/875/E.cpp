#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int x[N];

int s1, s2;

int n;

bool check(int m)
{
    set <int> s;
    s.insert(s1);
    s.insert(s2);
    if (abs(s1 - s2) > m) return false;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && abs(x[i] - x[i - 1]) <= m)
        {
            s.insert(x[i - 1]);
        }
        while (!s.empty() && abs(*s.begin() - x[i]) > m)
        {
            s.erase(s.begin());
        }
        while (!s.empty() && abs(*s.rbegin() - x[i]) > m)
        {
            s.erase(--s.end());
        }
        if (s.empty())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int l = -1, r = 1e9 + 7;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (check(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r << '\n';
}