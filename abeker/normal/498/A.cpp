#include <iostream>
using namespace std;

typedef long long ll;

int N, sol;
ll x1, y1, x2, y2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> N;
    while (N--) {
        ll a, b, c;
        cin >> a >> b >> c;
        sol += (a * x1 + b * y1 + c > 0) ^ (a * x2 + b * y2 + c > 0);
    }
    cout << sol << endl;
    return 0;
}