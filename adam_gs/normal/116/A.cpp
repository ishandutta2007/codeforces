#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ma=0;
    int w=0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        b-=a;
        w+=b;
        ma=max(ma, w);
    }
    cout << ma;
}