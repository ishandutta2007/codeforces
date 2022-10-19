#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    int i = 2;
    while (a%i!=0) {
        ++i;
    }
    cout << i << a/i;
}