#include <bits/stdc++.h>

using namespace std;

int n;
int a[2];
int x[2];

main()
{
    cin >> n;
    n /= 2;
    for (int I = 0; I < 2; I++){
        for (int i = 0; i < n; i++){
            char ch;
            cin >> ch;
            if (ch == '?'){
                x[I]++;
                continue;
            }
            a[I] += ch - '0';
        }
    }
    if (a[0] + (x[0] - x[1]) * 9 / 2 == a[1])
        cout << "Bicarp" << endl;
    else
        cout << "Monocarp" << endl;
    return 0;
}