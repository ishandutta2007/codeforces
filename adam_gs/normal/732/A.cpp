#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c=a;
    int r=1;
    while (c%10!=0 && c%10!=b) {
        c+=a;
        ++r;
    }
    cout << r;
}