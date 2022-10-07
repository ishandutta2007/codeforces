#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int R, D, U, L;
int a[10000];
int main()
{
   int n, i, k = 1, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
       cin >> a[i];
    }
    sort(a, a + n);
    i = 0;
    while (a[i] == i + 1 && i < n)
        i++;
    cout << i + 1;
    return 0;
}