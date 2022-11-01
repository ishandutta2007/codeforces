#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int n;
    int a, b, c;
    int x = 0;
    int y = 0;
    int z = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if(x != 0 || y != 0 || z != 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}