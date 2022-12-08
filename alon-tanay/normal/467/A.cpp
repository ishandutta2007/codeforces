#include <iostream>

using namespace std;

int main() {
    int n,p,q,sol = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> p >> q;
        if(q-p > 1) {
            sol ++;
        }
    }
    cout << sol;
    return 0;
}