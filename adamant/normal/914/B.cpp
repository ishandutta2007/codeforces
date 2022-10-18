#include <bits/stdc++.h> 

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int r = n, l = n - 1;
    while(true) {
        while(l > 0 && a[l - 1] == a[l]) {
            l--;
        }
        if((r - l) % 2 == 1) {
            cout << "Conan" << endl;
            return 0;
        } else if(l == 0) {
            cout << "Agasa" << endl;
            return 0;
        } else {
            r = l;
            l--;
        }
    }
    return 0;
}