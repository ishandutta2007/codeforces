#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t;
    long long int x, y, a, b;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> x >> y >> a >> b;
        if(b >= a*2 || ((x < 0) != (y < 0))) {
            cout << a*(abs(x)+abs(y)) << endl;
            continue;
        }
        x = abs(x);
        y = abs(y);
        cout << (min(x,y)*(b-a) + max(x,y)*a) << endl;
    }
    return 0;
}