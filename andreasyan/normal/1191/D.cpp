#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];
map<int, int> mp;
int main()
{
    bool z = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i])
            z = true;
        mp[a[i]]++;
    }
    if (!z)
    {
        cout << "cslnb" << endl;
        return 0;
    }
    int x = -1;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->second > 1)
        {
            x = it->first;
        }
    }
    if (x == 0)
    {
        cout << "cslnb" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == x)
        {
            --a[i];
            break;
        }
    }
    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(a[i]);
    if (s.size() != n)
    {
        cout << "cslnb" << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    long long q = 0;
    for (int i = 1; i <= n; ++i)
    {
        q += (a[i] - (i - 1));
    }
    if (x == -1)
    {
        if (q % 2 == 0)
            cout << "cslnb" << endl;
        else
            cout << "sjfnb" << endl;
    }
    else
    {
        if (q % 2 == 1)
            cout << "cslnb" << endl;
        else
            cout << "sjfnb" << endl;
    }
    return 0;
}