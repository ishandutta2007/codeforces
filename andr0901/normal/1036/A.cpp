#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long int n, k;
    cin >> n >> k;
    if (k % n == 0) cout << k / n;
    else cout << k / n + 1;
    return 0;
}