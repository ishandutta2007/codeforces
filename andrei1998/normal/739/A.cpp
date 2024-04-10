#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main()
{
    int n, m;
    cin >> n >> m;

    int smallest = n;

    while (m --) {
        int l, r;
        cin >> l >> r;
        smallest = min(smallest, r - l + 1);
    }

    cout << smallest << '\n';
    for (int i = 0; i < n; ++ i)
        cout << i % smallest << " \n"[i + 1 == n];
    return 0;
}