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

int n, i, j;

void solve4(int a1, int a2, int a3, int a4) {
    cout << a1 << ' ' << a3 << '\n';
    cout << a2 << ' ' << a4 << '\n';

    cout << a1 << ' ' << a2 << '\n';
    cout << a3 << ' ' << a4 << '\n';

    cout << a1 << ' ' << a4 << '\n';
    cout << a2 << ' ' << a3 << '\n';
}

void solve5(int a1, int a2, int a3, int a4, int a5) {
    cout << a1 << ' ' << a5 << '\n';
    cout << a1 << ' ' << a2 << '\n';
    cout << a2 << ' ' << a5 << '\n';
    cout << a1 << ' ' << a3 << '\n';
    cout << a2 << ' ' << a4 << '\n';
    cout << a1 << ' ' << a4 << '\n';
    cout << a2 << ' ' << a3 << '\n';
    cout << a3 << ' ' << a5 << '\n';
    cout << a3 << ' ' << a4 << '\n';
    cout << a4 << ' ' << a5 << '\n';
}

void combine(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    cout << a1 << ' ' << a5 << '\n';
    cout << a2 << ' ' << a6 << '\n';
    cout << a3 << ' ' << a7 << '\n';
    cout << a4 << ' ' << a8 << '\n';

    cout << a1 << ' ' << a8 << '\n';
    cout << a4 << ' ' << a5 << '\n';
    cout << a2 << ' ' << a7 << '\n';
    cout << a3 << ' ' << a6 << '\n';

    cout << a1 << ' ' << a6 << '\n';
    cout << a2 << ' ' << a5 << '\n';
    cout << a3 << ' ' << a8 << '\n';
    cout << a4 << ' ' << a7 << '\n';

    cout << a1 << ' ' << a7 << '\n';
    cout << a2 << ' ' << a8 << '\n';
    cout << a3 << ' ' << a5 << '\n';
    cout << a4 << ' ' << a6 << '\n';
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    if (n % 4 == 2 || n % 4 == 3) {
        cout << "NO";
    } else {
        cout << "YES\n";
        if (n % 4 == 0) {
            for (i = 1; i <= n; i += 4)
                solve4(i, i + 1, i + 2, i + 3);
        } else {
            for (i = 1; i <= n - 1; i += 4)
                solve5(i, i + 1, i + 2, i + 3, n);
        }

        for (i = 1; i <= n - 1; i += 4) {
            for (j = i + 4; j <= n - 1; j += 4) {
                combine(i, i + 1, i + 2, i + 3, j, j + 1, j + 2, j + 3);
            }
        }
    }


    return 0;
}