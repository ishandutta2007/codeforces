#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;

    int current;
    int last = 0;
    for (int i = 1; i <= n; ++ i) {
        cin >> current;
        ans += abs(last - current);
        last = current;
    }

    ans += (2 * n - 1);

    cout << ans << '\n';
    return 0;
}