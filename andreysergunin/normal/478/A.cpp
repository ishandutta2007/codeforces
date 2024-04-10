#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long ans, c1, c2, c3, c4, c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    ans = (c1 + c2 + c3 + c4 + c5) % 5;
    if (ans == 0 && c1 + c2 + c3 + c4 + c5 != 0)  cout << (c1 + c2 + c3 + c4 + c5) / 5;
    else cout << -1;
    return 0;
}