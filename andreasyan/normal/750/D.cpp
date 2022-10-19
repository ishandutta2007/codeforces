#include <bits/stdc++.h>
using namespace std;
const int xx[8] = {0, 1,  0, -1, 1, -1,  1, -1};
const int yy[8] = {1, 0, -1,  0, 1, -1, -1,  1};
const int t1[8] = {4, 4, 5, 5, 0, 2, 1, 0};
const int t2[8] = {7, 6, 6, 7, 1, 3, 2, 3};

map<int, map<int, bool> > c;
map<int, map<int, map<int, bool > > > mp;

int main()
{
    int n;
    cin >> n;
    mp[0][0][0] = true;
    while (n--)
    {
        int ss;
        cin >> ss;
        map<int, map<int, map<int, bool > > > nmp;
        for (map<int, map<int, map<int, bool > > >::iterator it = mp.begin(); it != mp.end(); ++it)
        {
            int x = it->first;
            for (map<int, map<int, bool> >::iterator it1 = mp[x].begin(); it1 != mp[x].end(); ++it1)
            {
                int y = it1->first;
                for (map<int, bool>::iterator it2 = mp[x][y].begin(); it2 != mp[x][y].end(); ++it2)
                {
                    int z = it2->first;
                    int cx = x;
                    int cy = y;
                    int cz = z;
                    for (int i = 0; i < ss; ++i)
                    {
                        int hx = x + xx[z];
                        int hy = y + yy[z];
                        /*if (i == 0)
                        {
                            hx = x;
                            hy = y;
                        }*/
                        x = hx;
                        y = hy;
                        c[x][y] = true;
                        if (i == ss - 1)
                        {
                            nmp[x][y][t1[z]] = true;
                            nmp[x][y][t2[z]] = true;
                        }
                    }
                    x = cx;
                    y = cy;
                    z = cz;
                }
            }
        }
        mp = nmp;
    }
    int ans = 0;
    for (map<int, map<int, bool> >::iterator it = c.begin(); it != c.end(); ++it)
        ans += it->second.size();
    cout << ans << endl;
    return 0;
}