#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[101];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int b[101];
    for(int i = 1; i <= n; i++)
        b[a[i]] = i;
    for(int i = 1; i <= n; i++)
        cout << b[i] << " ";
}