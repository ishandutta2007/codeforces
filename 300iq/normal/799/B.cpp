/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> kek[4][4];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector <int> p(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        kek[a[i]][b[i]].push_back(p[i]);
    }
    int m;
    scanf("%d", &m);
    for (int a = 1; a <= 3; a++)
    {
        for (int b = 1; b <= 3; b++)
        {
            sort(kek[a][b].rbegin(), kek[a][b].rend());
        }
    }
    for (int i = 0; i < m; i++)
    {
        int c;
        scanf("%d", &c);
        int x = -1, y = -1;
        int cst = 1e9 + 7;
        for (int a = 1; a <= 3; a++)
        {
            for (int b = 1; b <= 3; b++)
            {
                if ((a == c || b == c) && (kek[a][b].size()))
                {
                    if (kek[a][b].back() < cst)
                    {
                        x = a, y = b;
                        cst = kek[a][b].back();
                    }
                }
            }
        }
        if (x == -1)
        {
            printf("%d ", -1);
        }
        else
        {
            printf("%d ", kek[x][y].back());
            kek[x][y].pop_back();
        }
    }
}