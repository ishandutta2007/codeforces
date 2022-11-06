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

ll n, m;

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("*.out","w",stdout);

    cin >> n >> m;

    if (n > 30)
        cout << m;
    else
        cout << m % (1LL << n);


    return 0;
}