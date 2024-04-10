#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int b[n];
    long long s = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; s += x;
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n);
    if(s <= b[n - 2] + b[n - 1]) cout << "YES";
    else cout << "NO";
}