#include <iostream>

using namespace std;

int main()
{
    int ct;

    cin >> ct;
    for (int t = 0; t < ct; ++t)
    {
        long long n, k;
        cin >> n >> k;

        long long ans = -1;
        while (n > 0)
        {
            ans += n % k + 1;
            n /= k;
        }
        cout << ans << endl;
    }

    return 0;
}