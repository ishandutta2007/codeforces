#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    int q = 0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(q == 0 && s1[i] == 'h')
            q++;
        if(q == 1 && s1[i] == 'e')
            q++;
        if(q == 2 && s1[i] == 'l')
            q++;
        else
            if(q == 3 && s1[i] == 'l')
                q++;
        if(q == 4 && s1[i] == 'o')
            q++;
    }
    if(q == 5)
        cout << "YES";
    else
        cout << "NO";
}