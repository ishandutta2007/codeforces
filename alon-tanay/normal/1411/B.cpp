#include <iostream>

using namespace std;

bool bad(unsigned long long int n) {
    unsigned long long int x = n;
    while(x > 0) {
        if(x%10 != 0) {
            if(n%(x%10) != 0) { 
                return true;
            }
        }
        x /= 10;
    }
    return false;
}

int main() {
    int t;
    unsigned long long int n;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n;
        while(bad(n)) {
            n++;
        }
        cout << n << endl;
    }
    return 0;
}