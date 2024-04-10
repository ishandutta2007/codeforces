#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
struct edge
{
    int x, y;
};
edge a[1000];
string name[20], s1, s2;
string nameres1[20];
int n, k;

int getnum(string s)
{
    int i;
    for (i = 0; i < n; i++)
        if (s == name[i])
            return i;
}

int main()
{
    int i, j, res = 0, res1 = 0, d1, d2, ot;
    bool check;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> name[i];
    }
    for (i = 0; i < k; i++)
    {
        cin >> s1;
        cin >> s2;
        d1 = getnum(s1);
        d2 = getnum(s2);
        a[i].x = d1;
        a[i].y = d2;
    }
    for (i = 0; i < (1 << n); i++)
    {
        check = true;
        for (j = 0; j < k; j++)
        {
            if ((i & (1 << a[j].x)) != 0 && (i & (1 << a[j].y)) != 0)
                check = false;
        }
        if (check)
        {
            res1 = 0;
            for (j = 0; j < n; j++)
                if ((i & (1 << j)) != 0)
                    res1++;
        }
        if (res < res1)
        {
            res = res1;
            ot = i;
        }
    }
    cout << res << "\n";
    j = 0;
    for (i = 0; i < n; i++)
    {
        if ((ot & (1 << i)) != 0)
        {
            nameres1[j] = name[i];
            j++;
        }
    }
    sort(nameres1, nameres1 + res);
    for (i = 0; i < res; i++)
    {
        cout << nameres1[i] << "\n";
    }


    return 0;
}