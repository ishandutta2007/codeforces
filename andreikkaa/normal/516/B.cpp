#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <queue>

using namespace std;

int a[2002][2002];
int n, m;

bool is_one(int i, int j)
{
    if(i <= 0 or i >= n + 1 or j <= 0 or j >= m + 1)
        return false;

    if(a[i][j] != 1)
        return false;

    int c;
    c += a[i - 1][j] == 1;
    c += a[i][j - 1] == 1;
    c += a[i + 1][j] == 1;
    c += a[i][j + 1] == 1;
    return c == 1;
}

int main()
{
    for(int i = 0; i < 2002; ++i)
        memset(a[i], 0, 2002 * sizeof(int));


    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        char s[2002];
        scanf("%s", s + 1);
        for(int j = 1; j <= m; ++j)
        {
            char c = s[j];
            if(c == '.')
            {
                a[i][j] = 1;
            }
        }
    }

    /*for(int i = 0; i <= n + 1; ++i)
    {
        for(int j = 0; j <= m + 1; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;*/

    queue<pair<int, int>> q;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(is_one(i, j))
                q.push({i, j});
        }
    }

    /*
    2 = ^
    3 = v
    4 = <
    5 = >
    */

    while(not q.empty())
    {
        auto p = q.front();
        q.pop();

        int x = p.first, y = p.second;

        if(not is_one(x, y))
        {
            continue;
        }
        pair<int, int> ss;
        //cout << x << " & " << y << endl;
        if(a[x - 1][y] == 1)
        {
            a[x][y] = 3;
            a[x - 1][y] = 2;
            ss = {x - 1, y};
        }
        else if(a[x + 1][y] == 1)
        {
            a[x][y] = 2;
            a[x + 1][y] = 3;
            ss = {x + 1, y};
        }
        else if(a[x][y - 1] == 1)
        {
            a[x][y] = 5;
            a[x][y - 1] = 4;
            ss = {x, y - 1};
        }
        else
        {
            a[x][y] = 4;
            a[x][y + 1] = 5;
            ss = {x, y + 1};
        }

        if(is_one(x - 1, y))
            q.push({x - 1, y});

        if(is_one(x + 1, y))
            q.push({x + 1, y});

        if(is_one(x, y - 1))
            q.push({x, y - 1});

        if(is_one(x, y + 1))
            q.push({x, y + 1});

        x = ss.first;
        y = ss.second;

        if(is_one(x - 1, y))
            q.push({x - 1, y});

        if(is_one(x + 1, y))
            q.push({x + 1, y});

        if(is_one(x, y - 1))
            q.push({x, y - 1});

        if(is_one(x, y + 1))
            q.push({x, y + 1});

        /*for(int i = 0; i <= n + 1; ++i)
        {
            for(int j = 0; j <= m + 1; ++j)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << "END" << endl;*/
    }

    /*for(int i = 0; i <= n + 1; ++i)
    {
        for(int j = 0; j <= m + 1; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }*/

    for(int i = 0; i <= n + 1; ++i)
    {
        for(int j = 0; j <= m + 1; ++j)
        {
            if(a[i][j] == 1)
            {
                cout << "Not unique" << endl;
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            switch(a[i][j])
            {
            case 0: printf("*"); break;
            case 2: printf("^"); break;
            case 3: printf("v"); break;
            case 4: printf("<"); break;
            case 5: printf(">"); break;
            }
        }
        printf("\n");
    }



    return 0;
}