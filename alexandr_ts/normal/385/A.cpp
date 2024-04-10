#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int maxx = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i - 1] - a[i] > maxx)
            maxx = a[i - 1] - a[i];
    }
    maxx -= c;
    if(maxx <= 0)
        cout << 0;
    else
        cout << maxx;
    return 0;
}