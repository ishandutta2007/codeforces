#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 105;
const long double EPS = 1e-9;
long double a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    long double x = 1, y = 0;
    for(int i = 0; i < n; i++) {
        if(fabs(a[i] - 1) < EPS) {
            cout << a[i] << '\n';
            return 0;
        }
        if(x * y < x * (1 - a[i]) * (y + a[i] / (1 - a[i]))) {
            x *= (1 - a[i]);
            y += a[i] / (1 - a[i]);
        }
        else
            break;
    }
    cout << x * y << '\n';
    return 0;
}