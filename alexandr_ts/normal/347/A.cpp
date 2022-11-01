#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    swap(a[0], a[n - 1]);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}