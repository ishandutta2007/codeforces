#include <iostream>
#include <string>

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
            cout << "-1" << endl;
            continue;
        }
        cout << "2" << string(n-1, '3') << endl;
    }
    return 0;
}