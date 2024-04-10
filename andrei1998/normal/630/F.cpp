#include <iostream>

#define lint long long int
using namespace std;

int main()
{
    lint n;
    cin >> n;

    lint ans1 = n * (n - 1ll) * (n - 2ll) * (n - 3ll) * (n - 4ll);
    ans1 /= (5ll * 4 * 3 * 2 * 1);

    lint ans2 = ans1 * (n - 5ll);
    ans2 /= 6ll;

    lint ans3 = ans2 * (n - 6ll);
    ans3 /= 7ll;

    cout << ans1 + ans2 + ans3 << endl;
    return 0;
}