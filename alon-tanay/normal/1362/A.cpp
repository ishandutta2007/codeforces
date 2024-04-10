#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    long long int a,b,c,p;

    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        p = 0;
        cin >> a >> b;
        c = a;
        a = max(a,b);
        b = min(c,b);
        while(b < a) {
            p ++;
            b *= 2;
        }
        if(b != a) {
            cout << "-1" << endl;
            continue;
        }
        
        cout << (p/3)+(p%3==0 ? 0 : 1) << endl;
    }
    return 0;
}