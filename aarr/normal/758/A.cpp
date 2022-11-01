#include <iostream>
using namespace std;

int a[1000 * 1000 + 5];

int main() {
    int n, maxi = 0;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > maxi) {
            ans += 1ll * i * (a[i] - maxi);
            maxi = a[i];
        }
        else {
            ans += maxi - a[i];
        }
    }
    cout << ans << endl;
	return 0;
}