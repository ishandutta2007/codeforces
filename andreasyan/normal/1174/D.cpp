#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int n, x;

bool c[1 << N];

int z;
int p[1 << N];

int main()
{
    cin >> n >> x;
    c[x] = true;
    for (int y = 1; y < (1 << n); ++y)
    {
        if (c[y])
            continue;
        p[++z] = y;
        c[y] = true;
        c[y ^ x] = true;
    }
    cout << z << endl;
    for (int i = 1; i <= z; ++i)
        cout << (p[i] ^ p[i - 1]) << ' ';
    cout << endl;
    return 0;
}