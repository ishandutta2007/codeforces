#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += x;
    }
    ans /= n;
    cout << ans << endl;
}