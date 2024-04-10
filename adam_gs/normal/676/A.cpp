#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (c==1) {
            a=i;
        } else if (c==n) {
            b=i;
        }
    }
    cout << max(max(abs(a-0),abs(a-n+1)), max(abs(b-0), abs(b-n+1)));
}