#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <ctime>

using namespace std;

char arr[100];
vector<char> res[10010];

int row;

void a()
{
    res[row].push_back('.');
    res[row + 1].push_back('.');
}
void b()
{
    res[row].push_back('.');
    res[row + 1].push_back('X');
}
void c()
{
    res[row].push_back('X');
    res[row + 1].push_back('.');
}
void d()
{
    res[row].push_back('X');
    res[row + 1].push_back('X');
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%s", arr);
    n = strlen(arr);

    for(i = 0; i < n; i++)
    {
        int t = (int)arr[i];

        row = 3 * i;

        a();
        b();

        for(j = 0; j < t; j++)
        {
            d();
            b();
        }

        d();
        a();
        d();
        a();

        for(j = 0; j < t; j++)
        {
            b();
            a();
        }

        d();
        b();
        a();
    }

    int mx = 1;

    for(i = 0; i < 3 * n; i++)
        mx = max(mx, (int)res[i].size());

    for(i = 0; i < 3 * n; i++)
    {
        int t = mx - (int)res[i].size();
        for(j = 0; j < t; j++)
            res[i].push_back('.');
    }

    for(i = 0; i < 3 * n; i++)
    {
        for(char &t : res[i])
            printf("%c", t);
        printf("\n");
    }

    return 0;
}