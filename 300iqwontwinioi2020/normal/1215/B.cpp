#include <bits/stdc++.h>

using namespace std;

long long n;
long long a, b;

main()
{
    cin >> n;
    a++;
    int x = 1;
    for (int i = 0; i < n; i++){
        int y;
        cin >> y;
        if (y < 0)
            x *= -1;
        if (x == 1)
            a++;
        else
            b++;
    }
    cout << a * b << " " << n * (n + 1) / 2 - a * b << endl;
    return 0;
}