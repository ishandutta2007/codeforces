#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  //  freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int n, m, k;
    scanf("%d%d", &n, &m);
    if (n == 1 || m == 1){
        cout << n * m;
        return 0;
    }
    if (n == 2 || m == 2){
        if (m == 2)
            swap(n, m);
        m -= 2;
        k = 4;
        if (m % 4 == 0)
            k += n * m / 2;
        if (m % 4 == 1)
            k += n * (m - 1)/ 2;
        if (m % 4 == 2)
            k += n * (m - 2)/ 2;
        if (m % 4 == 3)
            k += n * (m - 3)/ 2 + 2;
        cout << k;
        return 0;
    }

    cout << (n * m + 1) / 2;
    return 0;
}