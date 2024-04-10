#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
int n;
int a[MAXN];


int main()
{
  //  freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 1; i < n; i++)
    {
        if (a[i - 1] * 2 > a[i] && a[i - 1] != a[i])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}