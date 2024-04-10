#include <iostream>

using namespace std;

int main() {
    long int n, sol = 0;
    char m, curr = '2';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> m >> m;
        if(m != curr) {
            sol ++;
            curr = m;
        }
    }
    cout << sol;
    return 0;
}