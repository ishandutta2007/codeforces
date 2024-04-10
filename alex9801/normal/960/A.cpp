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

using namespace std;

char arr[5000010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%s", arr);

    int a = 0, b = 0, c = 0, p = 0;
    bool ok = 1;
    for(i = 0; arr[i]; i++)
    {
        if(arr[i] == 'a')
        {
            if(p != 0)
                ok = 0;
            a++;
        }
        else if(arr[i] == 'b')
        {
            if(p == 0)
                p = 1;
            if(p != 1)
                ok = 0;
            b++;
        }
        else if(arr[i] == 'c')
        {
            if(p == 1)
                p = 2;
            if(p != 2)
                ok = 0;
            c++;
        }
        else
            ok = 0;
    }

    if(a == 0 || b == 0 || c != a && c != b)
        ok = 0;

    if(ok)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}