#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int w = 0;
    while(n--) {
        int a;
        cin >> a;
        w+=abs(a);
    }
    cout << w;
}