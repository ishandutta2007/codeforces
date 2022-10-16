#include <iostream>
#include <iomanip>

using namespace std;

double raise(double val, int exp) {
    double ans = 1;
    double aux = val;

    while (exp) {
        if (exp & 1)
            ans *= aux;

        aux *= aux;
        exp >>= 1;
    }

    return ans;
}

double v[128];

void FWHT() {
    for (int len = 2; len <= 128; len *= 2) {
        for (int start = 0; start < 128; start += len) {
            for (int i = 0; i < len / 2; ++ i) {
                double a = v[start + i];
                double b = v[start + i + len / 2];

                v[start + i] = a + b;
                v[start + i + len / 2] = a - b;
            }
        }
    }
}

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i <= x; ++ i)
        cin >> v[i];

    FWHT();
    for (int i = 0; i < 128; ++ i)
        v[i] = raise(v[i], n);
    FWHT();

    for (int i = 0; i <= x; ++ i)
        v[i] /= 128;

    cout << fixed << setprecision(8);
    cout << 1 - v[0] << '\n';

    return 0;
}