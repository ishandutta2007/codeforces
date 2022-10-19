#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r=0;
    int a=0;
    while (n--) {
        int q;
        cin >> q;
        a+=q;
        if (a<0) {
            ++r;
            ++a;
        }
    }
    cout << r;
}