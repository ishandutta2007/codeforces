#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, sum = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a >> b >> c;
        sum += (a+b+c)/2;
    }
    cout << sum;
    return 0;
}