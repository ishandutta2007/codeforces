#include <bits/stdc++.h>

using namespace std;

int euk(int a, int b) {
    if (a==0){
            return b;
    } else {
        return euk(b%a, a);
    }
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int l=0;
    while (n>0) {
        if (l%2==0) {
            n-=euk(a, n);
        } else {
            n-=euk(b, n);
        }
        ++l;
    }
    if (l%2==1) {
        cout << 0;
    } else {
        cout << 1;
    }
}