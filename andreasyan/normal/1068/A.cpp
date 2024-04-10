#include <bits/stdc++.h>
using namespace std;

long long n, m, k, l;

int main()
{
    cin >> n >> m >> k >> l;
    long long rr = n / m;
    long long ll = (l + k) / m + !!((l + k) % m);
    if (ll <= rr)
        cout << ll << endl;
    else
        cout << -1 << endl;
    return 0;
}