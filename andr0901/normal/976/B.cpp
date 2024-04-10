#include <iostream>

using namespace std;

int main()
{
    int n, m;
    long long int k;
    cin >> n >> m >> k;
    if (k < n) cout << k + 1 << " " << 1;
    else if (((k - n) / (m - 1)) % 2 == 0) {
        cout << n - ((k - n) / (m - 1)) << " " << (k - n) % (m - 1) + 2;
    }
    else {
        cout << n - ((k - n) / (m - 1)) << " " << m - (k - n) % (m - 1);
    }
    return 0;
}