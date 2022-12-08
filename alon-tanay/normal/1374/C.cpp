#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, len, deg, sol;
    string input;

    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        deg = 0;
        sol = 0;
        cin >> len;
        cin >> input;
        for(int j = 0; j < len; j ++) {
            deg += (((input[j]=='(') ? 1 : -1));
            if(deg < 0) {
                deg = 0;
                sol ++;
            }
        }
        cout << sol << endl;
    }
    return 0;
}