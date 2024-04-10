#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    long long c, d;
    cin >> c >> d;
    
    for(int iTime = 0;iTime < 100 * 1000;iTime++) {
        if((a * iTime + b - d) % c == 0 && a * iTime + b - d >= 0) {
            cout << b + a * iTime << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
}