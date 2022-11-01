#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;

struct tmp
{
    int x, y;
};

tmp a[100000];
bool c[10000][4];

bool cmp(tmp a, tmp b)
{
    return a.x > b.x;
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i].x == a[j].x && a[i].y < a[j].y)
                c[i][0] = true;
            if (a[i].x == a[j].x && a[i].y > a[j].y)
                c[i][1] = true;
            if (a[i].y == a[j].y && a[i].x < a[j].x)
                c[i][2] = true;
            if (a[i].y == a[j].y && a[i].x > a[j].x)
                c[i][3] = true;
        }
    int qua = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i][0] && c[i][1] && c[i][2] && c[i][3])
            qua++;
    }
    cout << qua;

}