#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long


int main()
{
    //freopen("test.in","r",stdin);


    int n, i, ans = 0;
    cin >> n;
    for (i = 1; i < n; i++)
        if ((n - i) % i == 0)
            ans++;

    cout << ans;




    return 0;
}