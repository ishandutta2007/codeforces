#include <iostream>
#include <vector>

using namespace std;

main()
{
    int ara[12][12];
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ara[1][i] = 1;
        ara[i][1] = 1;
    }
    int Max = 1;
    for (int j = 2; j <= n; j++) {
        for (int k = 2; k <= n; k++) {
            ara[k][j] = ara[k][j-1] + ara[k-1][j];
            if (ara[k][j] > Max) Max = ara[k][j];
        }
    }
    cout << Max << endl;
}