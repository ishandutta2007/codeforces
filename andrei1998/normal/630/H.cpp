#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int ans1 = n * (n - 1ll) * (n - 2ll) * (n - 3ll) * (n - 4ll);
    cout << ans1 / (5ll * 4 * 3 * 2 * 1) * ans1 << endl;
    return 0;
}