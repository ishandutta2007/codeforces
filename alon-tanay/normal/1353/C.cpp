#include <iostream>

using namespace std;

int main() {
    int t;
    long long int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n;
        cout << 4*(n/2)*((n/2)+1)*n/3 << endl;
    }
    return 0;
}