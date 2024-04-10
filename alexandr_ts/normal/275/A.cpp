#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;

int a[10][10];

int c[10][10];

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            c[i][j] = a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            int temp = c[i][j] & 1;
            cout << !temp;
        }
        cout << endl;
    }

}