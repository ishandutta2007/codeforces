#include <cstdio>
#include <iostream>
#include <ctime>

using namespace std;


long long a, b;
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    cin >> a >> b >> n;

    for (int i = 2; i <= n; i++)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << b << endl;

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}