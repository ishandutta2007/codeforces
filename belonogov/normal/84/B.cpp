#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n, a[1000];

int main()
{
    int i, n, a[100010];
    long long k, sum;
    cin >> n;
    for (i = 0; i < n; i++)
    {
       cin >> a[i];
    }

    sum = n;
    k = 1;
    for (i = 1; i < n; i++)
    {
      if (a[i] == a[i - 1])
      {
        k++;
      }else{
        sum = sum + (k * (k - 1)) / 2;
        k = 1;
      }
    }
    sum = sum + (k * (k - 1)) / 2;
    cout << sum;

    return 0;
}