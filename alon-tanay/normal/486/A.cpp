#include <iostream>

using namespace std;

int main() {
    long long int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << (n%2 ? -n/2-1 : n/2);
    return 0;
}