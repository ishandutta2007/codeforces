#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int a[10000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        cout << (x + 1) % 2 << "\n";
    }


    return 0;
}