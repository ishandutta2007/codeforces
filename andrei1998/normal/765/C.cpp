#include <iostream>

#define int long long int
using namespace std;

signed main()
{
    int k, a, b;
    cin >> k >> a >> b;

    int ansA = a / k;
    int ansB = b / k;

    a %= k;
    b %= k;

    if (a > 0 && !ansB) {
        cout << "-1\n";
        return 0;
    }
    if (b > 0 && !ansA) {
        cout << "-1\n";
        return 0;
    }

    cout << ansA + ansB << '\n';
    return 0;
}