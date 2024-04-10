#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
struct ban
{
    int x, y;
};

int n;
ban a[N];
ban b[N];

map<int, map<int, int> > mp;

bool c[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &b[i].x, &b[i].y);
        mp[b[i].x][b[i].y] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        int x = a[0].x + b[i].x;
        int y = a[0].y + b[i].y;
        for (int j = 0; j < n; ++j)
            c[j] = false;
        bool z = true;
        for (int j = 1; j < n; ++j)
        {
            int xx = x - a[j].x;
            int yy = y - a[j].y;
            if (mp[xx].find(yy) == mp[xx].end())
            {
                z = false;
                break;
            }
            int ii = mp[xx][yy];
            if (c[ii])
            {
                z = false;
                break;
            }
            c[ii] = true;
        }
        if (z)
        {
            cout << x << ' ' << y << endl;
            return 0;
        }
    }
    return 0;
}