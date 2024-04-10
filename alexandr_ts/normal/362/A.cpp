#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 10000000;

int a[100][100];
int b[100][100];
int useda[100][100];
int usedb[100][100];

void dfs1(int x, int y)
{
    useda[x][y] = 1;
    if(x - 2 >= 0)
    {
        if(y - 2 >= 0)
            if(useda[x - 2][y - 2] == 0)
                dfs1(x - 2, y - 2);
        if(y + 2 <= 7)
            if(useda[x - 2][y + 2] == 0)
                dfs1(x - 2, y + 2);
    }
    if(x + 2 <= 7)
    {
        if(y - 2 >= 0)
            if(useda[x + 2][y - 2] == 0)
                dfs1(x + 2, y - 2);
        if(y + 2 <= 7)
            if(useda[x + 2][y + 2] == 0)
                dfs1(x + 2, y + 2);
    }
}

void dfs2(int x, int y)
{
    usedb[x][y] = 1;
    if(x - 2 >= 0)
    {
        if(y - 2 >= 0)
            if(usedb[x - 2][y - 2] == 0)
                dfs2(x - 2, y - 2);
        if(y + 2 <= 7)
            if(usedb[x - 2][y + 2] == 0)
                dfs2(x - 2, y + 2);
    }
    if(x + 2 <= 7)
    {
        if(y - 2 >= 0)
            if(usedb[x + 2][y - 2] == 0)
                dfs2(x + 2, y - 2);
        if(y + 2 <= 7)
            if(usedb[x + 2][y + 2] == 0)
                dfs2(x + 2, y + 2);
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    char temp;
    bool ans;
    int k1x, k1y, k2x, k2y;
    k1x = -1;

    for(int i = 0; i < n; i++)
    {
        ans = false;
        k1x = -1;
        for(int j = 0; j < 8; j++)
            for(int k = 0; k < 8; k++)
            {
                cin >> temp;
                useda[j][k] = 0;
                usedb[j][k] = 0;
                if(temp == 'K')
                {
                    if(k1x == -1)
                    {
                        k1x = j;
                        k1y = k;
                    }
                    else
                    {
                        k2x = j;
                        k2y = k;
                    }
                    a[j][k] = 1;
                }
                if(temp == '.')
                    a[j][k] = 2;
                if(temp == '#')
                    a[j][k] = 3;
            }

        if(((k1x - k2x + 8) % 4 == 0) && ((k1y - k2y + 8) % 4 == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        //cout << k1x << " " << k1y << " " << k2x << " " << k2y << endl;

    }
    return 0;
}