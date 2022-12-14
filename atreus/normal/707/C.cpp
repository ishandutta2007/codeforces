#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    if (n == 1 || n == 2)
        return cout << -1, 0;
    if (n % 2 == 0){
        long long k = pow(n, 2);
        k /= 2;
        cout << k / 2 + 1 << " " << k / 2 - 1 << endl;
        return 0;
    }
    if (n % 2 == 1){
        long long k = pow(n, 2);
        cout << k / 2 + 1 << " " << k / 2 << endl;
        return 0;
    }
}