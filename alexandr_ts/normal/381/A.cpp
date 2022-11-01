#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

int a[10000000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0;
    int r = n - 1;
    int s1 = 0;
    int s2 = 0;
    int cur = 0;
    while(r - l >= 0)
    {
        if(a[l] > a[r])
        {
            if(cur == 0)
                s1 += a[l];
            else
                s2 += a[l];
            l++;
            cur = cur xor 1;
        }
        else
        {
            if(cur == 0)
                s1 += a[r];
            else
                s2 += a[r];
            r--;
            cur = cur xor 1;
        }
    }
    cout << s1 << " "  << s2;
    return 0;
}