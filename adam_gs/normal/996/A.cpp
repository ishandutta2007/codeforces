#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int w=0;
    while (n>=100) {
        n-=100;
        ++w;
    }
    while (n>=20) {
        n-=20;
        ++w;
    }
    while (n>=10) {
        n-=10;
        ++w;
    }
    while (n>=5) {
        n-=5;
        ++w;
    }
    while (n>=1) {
        --n;
        ++w;
    }
    cout << w;
}