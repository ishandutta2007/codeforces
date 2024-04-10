#include <iostream>

using namespace std;

int main() {
    int t, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n >> m;
        if(n == 1) {
            cout << "BWB";
            for(int j = 3; j < m; j ++) {
                cout << "B";
            }
            cout << endl;
            continue;
        }
        if(m == 1) {
            cout << "B\nW\nB" << endl;
            for(int j = 3; j < n; j ++) {
                cout << "B" << endl;
            }
            continue;
        }
        for(int j = 0; j < n*m; j ++) {
            if(j < m-1) {
                cout << "W";
                continue;
            }
            cout << "B";
            if((j+1)%m == 0) {
                cout << endl;
            }
        }
    }
    return 0;
}