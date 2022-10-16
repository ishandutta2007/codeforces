#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main()
{
    lint N, K;
    cin >> N >> K;

    lint x = N / (2 * (K + 1));

    cout << x << ' ' << x * K << ' ' << N - (K + 1) * x << '\n';
    return 0;
}