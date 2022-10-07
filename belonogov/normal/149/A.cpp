#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[100];

int main()
{
    int i, k, sum = 0;
    cin >> k;
    for (i = 0; i < 12; i++)
        cin >> a[i];
    sort(a, a + 12);
    i = 11;
    while (sum < k && i >= 0){
        sum += a[i];
        i--;
    }
    if (sum < k)
        cout << -1;
    else
        cout << 11 - i;
    return 0;
}