#include <iostream>

#define lint long long int
using namespace std;

int d[1000006];

int main()
{
    lint sum = 0, A;
    int n;
    cin >> n >> A;

    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        sum += d[i];
    }

    lint x, y;
    for (int i = 1; i <= n; i++) {
        x = max(1ll, A + d[i] - sum);
        y = min(1ll * d[i], A + 1 - n);

        if (y < x) {
            cout << d[i] << ' ';
        }
        else
            cout << d[i] - (y - x + 1) << ' ';
    }
    cout << endl;

    return 0;
}