#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
map<int, vector<int> > mp;

bool c[N];

int q[N];
int qq;

int p[N];
int d[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    if (x == 5 && y == 4)
        cout << "";
    x = fi(x);
    y = fi(y);

    q[d[x]]--;
    q[d[y]]--;

    p[x] = y;
    d[y] += d[x];

    q[d[y]]++;

    --qq;
}



int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        d[i] = 1;
    }

    int ans = 0, ansq = 0;

    for (map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        vector<int> v = it->second;
        for (int i = 0; i < v.size(); ++i)
        {
            int x = v[i];
            c[x] = true;

            ++q[d[x]];
            ++qq;

            if (c[x + 1] == true)
            {
                kpc(x, x + 1);
            }
            if (c[x - 1] == true)
            {
                kpc(x, x - 1);
            }
        }
        int x = v[0];
        int dd = d[fi(x)];
        if (q[dd] == qq)
        {
            if (qq > ansq)
            {
                ansq = qq;
                ans = it->first + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}