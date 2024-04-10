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
    cin >> n;
    bool tr = false;
    if(n % 4 == 0)
        tr = true;
    if(n % 7 == 0)
        tr = true;
    if(n % 44 == 0)
        tr = true;
    if(n % 47 == 0)
        tr = true;
    if(n % 74 == 0)
        tr = true;
    if(n % 77 == 0)
        tr = true;
    if(n % 444 == 0)
        tr = true;
    if(n % 447 == 0)
        tr = true;
    if(n % 474 == 0)
        tr = true;
    if(n % 477 == 0)
        tr = true;
    if(n % 744 == 0)
        tr = true;
    if(n % 747 == 0)
        tr = true;
    if(n % 774 == 0)
        tr = true;
    if(n % 777 == 0)
        tr = true;
    if(tr)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}