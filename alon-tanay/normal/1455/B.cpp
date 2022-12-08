#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    long int x, j, d;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> x;
        j = ceil((sqrt(8.0*x+1.0)-1.0)/2);
        d = (j*(j+1))/2-x;
        if(d == 1) {
            cout << j+1 << endl;
            continue;
        }
        cout << j << endl;
    }
    return 0;
}