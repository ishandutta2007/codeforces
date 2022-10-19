#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a=0, b=0, c=0, d=0;
    while (n--) {
        int l;
        cin >> l;
        if (l%2==0) {
            ++a;
        } else {
            ++b;
        }
    }
    while (m--) {
        int l;
        cin >> l;
        if (l%2==0) {
            ++c;
        } else {
            ++d;
        }
    }
    cout << min(a, d)+min(b, c);
}