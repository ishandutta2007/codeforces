#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct prr
{
    int x1, x2, x3, cost, i;
    bool check;
};

bool operator < (prr a, prr b)
{
    return a.cost < b.cost;
}
int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    int n, i, j;
    prr a[1000];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].x1 >> a[i].x2 >> a[i].x3 >> a[i].cost;
        a[i].check = true;
        a[i].i = i + 1;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (a[i].x1 > a[j].x1 && a[i].x2 > a[j].x2 && a[i].x3 > a[j].x3)
                a[j].check = false;
        }
    sort(a, a + n);
    i = 0;
    while(! a[i].check)
    {
        i++;
    }
    cout << a[i].i;

    return 0;
}