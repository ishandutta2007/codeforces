#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    int n;
    cin >> n;
    int su = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        su += a[i];
    }
    sort(a, a + n);
    int i = n - 1;
    int su1 = 0;
    int qua = 0;
    while(2 * su1 <= su)
    {
        su1 += a[i];
        i--;
        qua++;
    }
    cout << qua;
    return 0;
}