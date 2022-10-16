#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100 + 5;

int n;
int v[NMAX];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    int sz = 0;
    for (int i = 1; i <= n; ++ i) {
        int val = v[i];

        int j;
        for (j = sz; j > 0; -- j)
            if (v[j] <= val)
                break;

        if (j == 0)
            v[++ sz] = 1;
        else
            ++ v[j];
    }

    cout << sz << '\n';
    return 0;
}