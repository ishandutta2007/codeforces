#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s=0;
    int m=0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s+=a;
        m=max(m, a);
    }
    cout << m*n-s;
}