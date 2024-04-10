#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int a, b, s, d;
    cin >> a >> b >> s;
    d = abs(a) + abs(b);
    if(s < d)
    {
        cout << "No" << endl;
    }
    else if(s % 2 == d % 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

}