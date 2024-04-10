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
    int n, i, j, sum, k, uk;
    bool check;

    cin >> n >> k;
    uk = 0;
    for (i = 2; i < n + 100; i++)
    {
        check = true;
        for (j = 0; j < uk; j++)
            if (i % a[j] == 0)
                check = false;
        if (check)
            a[uk++] = i;
    }
    sum = 0;
    for (i = 1; a[i] <= n; i++)
        for (j = 0; j < i; j++)
            if (a[j] + a[j + 1] + 1 == a[i])
                sum++;

    if (sum >= k)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}