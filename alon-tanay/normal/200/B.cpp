#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, a;
    double sum = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a;
        sum += a;
    }
    cout << (sum/n);
    return 0;
}