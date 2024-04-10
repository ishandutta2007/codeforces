#include <iostream>

using namespace std;

const int NMAX = 100 + 5;
int v[NMAX];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++ i)
        v[i] = 1;
    for (int i = 2; i <= b + 1; ++ i)
        v[i] = 2 * v[i - 1];

    if (b == 0 && a > 0) {
        for (int i = 3; i <= a + 2; ++ i)
            v[i] = v[i - 1] + 1;
        if (a + 2 > n) {
            cout << "-1\n";
            return 0;
        }
    }
    else
        for (int i = b + 2; i <= b + 1 + a; ++ i)
        v[i] = v[i - 1] + 1;

    if (v[a + b + 1] > 50000) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; ++ i)
        cout << v[i] << " \n"[i == n];
    return 0;
}