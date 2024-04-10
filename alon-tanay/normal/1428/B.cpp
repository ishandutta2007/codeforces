#include <iostream>

using namespace std;

int main() {
    int t;
    long int n, sol;
    char c;
    bool cw, ccw, last, curr, first;
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n;
        cw = true;
        ccw = true;
        last = false;
        sol = 0;
        for(long int j = 0; j < n; j ++) {
            cin >> c;
            curr = (c=='-');
            if(last || curr){sol ++;}
            last = curr;
            if(j == 0) {first = curr;}
            if(c == '>') {
                ccw = false;
            } else if(c == '<') {
                cw = false;
            }
        }
        if(cw || ccw) {
            cout << n << endl;
            continue;
        }
        if(last && !first) {
            sol ++;
        }
        cout << sol << endl;
    }
    return 0;
}