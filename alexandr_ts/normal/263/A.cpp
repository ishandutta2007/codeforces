#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int temp;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
        {
            cin >> temp;
            if(temp)
            {
                cout << fabs(2 - i) + fabs(2 - j);
                return 0;
            }
        }
    return 0;

}