#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        int val;
        cin >> val;

        ans = __gcd(ans, val);
    }

    cout << ans * n << '\n';
    return 0;
}