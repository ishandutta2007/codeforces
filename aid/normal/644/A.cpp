#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    if(n > a * b) {
        cout << -1 << '\n';
        return 0;
    }
    int l = 0, r = 1;
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++)
            if(!((i + j) & 1)) {
                if(l < n) {
                    cout << l + 1 << ' ';
                    l += 2;
                }
                else
                    cout << 0 << ' ';
            }
            else {
                if(r < n) {
                    cout << r + 1 << ' ';
                    r += 2;
                }
                else
                    cout << 0 << ' ';
            }
        cout << '\n';
    }
    return 0;
}