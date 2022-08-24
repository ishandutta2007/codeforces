#include <bits/stdc++.h>

using namespace std;

bool simple(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (n == 3) {
        cout << 1 << endl << 3 << endl;
    }
    else if (n == 5) {
        cout << 2 << endl << 2 << " " << 3 << endl;
    }
    else {
        vector <int> ans;
        n -= 3;
        ans.push_back(3);
        for (int i = 2; i <= n; i++) {
            if (simple(i) && simple(n - i)) {
                cout << 3 << endl << 3 << " " << n - i << " " << i << endl;
                break;
            }
        }
    }
}