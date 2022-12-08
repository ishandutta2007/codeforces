#include <iostream>

using namespace std;

int main() {
    int n,h,a;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    int sol = n;
    for(int i = 0; i < n; i ++) {
        cin >> a;
        if(a > h) {
            sol ++;
        }
    }
    cout << sol;
    return 0;
}