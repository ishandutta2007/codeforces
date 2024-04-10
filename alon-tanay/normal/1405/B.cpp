#include <iostream>

using namespace std;

int main() {
    int t;
    unsigned long n;
    long long int a, dec_carry, inc_carry, sol;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        dec_carry = 0;
        inc_carry = 0;
        sol = 0;
        cin >> n;
        for(int j = 0; j < n; j ++) {
            cin >> a;
            if(a == 0) {
                continue;
            }
            if(a > 0) {
                inc_carry += a;
                continue;
            }
            

            if(a <= -inc_carry) {
                sol -= a+inc_carry;
                inc_carry = 0;
                continue;
            }
            inc_carry += a;
        }
        cout << sol << endl;
    }
    return 0;
}