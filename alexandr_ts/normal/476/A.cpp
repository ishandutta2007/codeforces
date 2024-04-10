#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int cur = (n + 1) / 2;
    while (cur % m)
        cur++;
    if (cur > n)
        cout << -1;
    else
        cout << cur;
}