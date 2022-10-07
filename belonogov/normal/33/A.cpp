#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//vector <int> a;
int a[100000];
int b[100000];

int main()
{
  int n, m, i, x, y, sum, k;
    cin >> n >> m >> k;
    for (i = 0; i < m; i++)
        a[i] = 1e7;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        x--;
        a[x] = min(a[x], y);
    }
    sum = 0;
    for (i = 0; i < m; i++)
        sum += a[i];

    cout << min (sum, k);


    return 0;
}