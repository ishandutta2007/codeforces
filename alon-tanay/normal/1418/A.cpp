#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    unsigned long long int x,y,k,sol;

    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> x >> y >> k;
        sol = (k*(y+1)-1)/(x-1);
        if(sol * (x-1) != k*(y+1)-1) {
            sol ++;
        }
        cout << (sol + k) << endl;
    }
    return 0;
}