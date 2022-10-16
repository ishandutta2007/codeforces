#include <iostream>

#define lint long long int
using namespace std;

lint put4[100];

int main()
{
    int n = 0;
    cin >> n;

    put4[0] = 1;
    for (int i = 1; i < 100; ++ i)
        put4[i] = 4ll * put4[i - 1];

    long long int ans = 0;

    for (int i = 2; i + n - 1 < 2 * n - 2; ++ i) {
        ans += 36ll * put4[n - 4];
    }

    ans += 2ll * 4 * 3 * put4[n - 3];

    cout << ans << '\n';
    return 0;
}