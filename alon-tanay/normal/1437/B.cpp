#include <iostream>

using namespace std;

int main() {
    int t;
    long int n, sol;
    char c;
    bool last_one, first_one;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n;
        sol = 0;
        for(long int j = 0; j < n; j ++) {
            cin >> c;
            if(j == 0) {
                if(c == '1') {
                    first_one = true;
                    last_one = true;
                    continue;
                }
                first_one = false;
                last_one = false;
                continue;
            }
            if(c == '1') {
                if(last_one) {
                    sol ++;
                    continue;
                }
                last_one = true;
                continue;
            }
            last_one = false;
        }
        if(c=='1' && first_one) {
            sol ++;
        }
        cout << sol << endl;
    }
    return 0;
}