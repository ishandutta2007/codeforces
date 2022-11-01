#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1000000;

long long a[maxn];

int main()
{
    long long n, m;
    cin >> n >> m;
    for(long long i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    if(m == 0)
        cout << "YES";
    else
    {


    int er = 0;
    for(long long i = 0; i < m - 1; i++)
        if(a[i]+ 2 == a[i + 1] + 1 && a[i + 1] + 1 == a[i + 2])
            er = 1;
    if(a[0] == 1)
        er = 1;
    if(a[m - 1] == n)
        er = 1;
    if(er == 1)
        cout << "NO";
    else
        cout << "YES";
    }

    return 0;
}