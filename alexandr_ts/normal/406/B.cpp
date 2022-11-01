#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[2000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        a[temp] = 1;
    }
    int l = 500000;
    int r = 500001;
    int qua = 0;
    while(l >= 1 && r <= 1000000)
    {
        if(a[l] == 1 && a[r] == 1)
            qua++;
        if(a[l] == 1 && a[r] == 0)
            a[r] = 2;
        if(a[l] == 0 && a[r] == 1)
            a[l] = 2;
        if(qua > 0 && a[l] == 0 && a[r] == 0)
        {
            a[l] = 2;
            a[r] = 2;
            qua--;
        }
        l--;
        r++;
    }
    l = 1;
    r = 1000000;
    while(l <= 500000 && r >= 500001)
    {
        if(a[l] == 0 && a[r] == 0 && qua > 0)
        {
            a[l] = 2;
            a[r] = 2;
            qua--;
        }
        l++;
        r--;
    }
    int quan = 0;
    for(int i = 0; i < 1000001; i++)
        if(a[i] == 2)
        {
            quan++;
        }
    if(quan != 0)
        cout<< quan << endl;
    bool writ = false;
    for(int i = 0; i < 1000001; i++)
        if(a[i] == 2)
        {
            printf("%d ", i);
            writ = true;
        }
    if(!writ)
        if(a[1] != 1)
            cout << 1 << endl << 1;
        else
            if(a[1000000] != 1)
                cout << 1 << endl << 1000000;
            else
                cout << 0;
    return 0;
}