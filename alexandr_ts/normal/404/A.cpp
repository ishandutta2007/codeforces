#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;

int a[1000][1000];

int main()
{
    ll n;
    cin >> n;
    char t1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> t1;
            a[i][j] = (int)(t1 - 'a');
        }
    bool er = false;
    for(int i = 1; i < n; i++)
        if(a[i][i] != a[i - 1][i - 1])
            er = true;
    for(int i = 1; i < n; i++)
        if(a[i][n - i - 1] != a[i - 1][n - i])
            er = true;
    if(a[0][0] != a[0][n - 1])
        er = true;
    if(a[0][0] == a[0][1])
        er = true;
    char onl = a[0][1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && i != (n - j - 1))
                if(a[i][j] != onl)
                    er = true;
    if(er)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}