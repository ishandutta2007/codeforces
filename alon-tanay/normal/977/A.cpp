#include <iostream>

using namespace std;

int main() {
    long long int n;
    int k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    
    while(k > n%10) {
        k -= n%10 + 1;
        n /= 10;  
    }
    cout << n-k;
    return 0;
}