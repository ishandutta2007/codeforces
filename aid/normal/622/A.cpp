#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long k = 1;
    while(k < n) {
        n -= k;
        k++;
    }
    cout << n << '\n';
    return 0;
}