#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int ans = 0;
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(b < x && x < c) {
            ans++;
        }
    }
    cout << ans;
}