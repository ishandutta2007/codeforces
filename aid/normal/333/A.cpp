#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long k = 1;
    while(!(n % k))
        k *= 3;
    cout << (n - 1) / k + 1 << '\n';
}