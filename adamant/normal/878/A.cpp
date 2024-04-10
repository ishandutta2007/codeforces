#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res[2] = {0, 1023};
    for(int i = 0; i < n; i++) {
        char t;
        cin >> t;
        int x;
        cin >> x;
        if(t == '|') {
            res[0] |= x, res[1] |= x;
        } else if(t == '&') {
            res[0] &= x, res[1] &= x;
        } else {
            res[0] ^= x, res[1] ^= x;
        }
    }
    for(int a = 0; a < 1024; a++) {
        for(int b = 0; b < 1024; b++) {
            if((((0 | a) & b) ^ res[0]) == (((1023 | a) & b) ^ res[1])) {
                cout << 3 << "\n";
                cout << "| " << a << "\n";
                cout << "& " << b << "\n";
                cout << "^ " << (((0 | a) & b) ^ res[0]) << "\n";
                return 0;
            }
        }
    }
}