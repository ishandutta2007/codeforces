#include <iostream>

using namespace std;

int main() {
    int t;
    long int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n;
        if(n == 1) {
            cout << "1" << endl;
            continue;
        }
        if(n == 2) { 
            cout << "2\n2 1" << endl;
            continue;
        }
        cout << "2" << endl;
        cout << n << " " << n-2 << endl;
        cout << n-1 << " " << n-1 << endl;
        for(int j = n-1; j > 2; j--) {
            cout << j << " " << j-2 << endl;
        }
    }
    return 0;
}