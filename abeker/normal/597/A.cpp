#include <iostream>
using namespace std;

int main() {
    long long A, B, K;
    cin >> K >> A >> B;
    if (A > 0) cout << B / K - (A - 1) / K << endl;
    else if (B >= 0) cout << B / K - A / K + 1 << endl;
    else cout << (B + 1) / K - A / K << endl;
    return 0;    
}