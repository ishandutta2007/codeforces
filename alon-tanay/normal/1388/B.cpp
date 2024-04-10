#include <iostream>

using namespace std;

int main() {
    int t, n;
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            if(j < n-1-((n-1)/4)) {
                cout << "9";
                continue;
            }
            cout << "8";
        }
        cout << endl;
    }
    return 0;
}