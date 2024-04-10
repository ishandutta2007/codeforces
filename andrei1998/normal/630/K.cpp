#include <iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    long long int ans = n - n / 2 - n / 3 - n / 5 - n / 7 + n / 6 + n / 10 + n / 14 + n / 15 + n / 35 + n / 21
                          - n / (210 / 2) - n / (210 / 3) - n  / (210 / 5) - n / (210 / 7) + n / (210);

    cout << ans << endl;
    return 0;
}