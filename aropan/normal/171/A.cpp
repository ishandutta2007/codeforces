#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

long long n, m, x;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    cin >> n >> m;
    do x = x * 10 + m % 10; while (m /= 10);
    cout << n + x << endl;
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}