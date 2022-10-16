#include <bits/stdc++.h>

using namespace std;

map <int, int> l1;
map <int, int> l2;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, x, y;
    cin >> n;

    long long int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        cin >> x >> y;

        ans += l1[x + y] + l2[x - y];

        l1[x + y] ++;
        l2[x - y] ++;
    }

    cout << ans << '\n';
    return 0;
}