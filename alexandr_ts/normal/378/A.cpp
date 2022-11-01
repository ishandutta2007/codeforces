#include <bits/stdc++.h>

using namespace std;

int a[10000];

main()
{
    int a, b;
    cin >> a >> b;
    int aw, dr, bw;
    aw = dr = bw = 0;
    for (int i = 1; i <= 6; i++)
        if (abs(i - a) == abs(i - b))
            dr++;
        else if (abs(i - a) < abs(i - b))
            aw++;
        else
            bw++;
    cout << aw << " " << dr << " " << bw;
}