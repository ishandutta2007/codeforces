#include <bits/stdc++.h>

using namespace std;
struct fly {
    int l;
};
int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <fly> a(n);
    for ( int i = 0; i < n; i++) {
        int now;
        cin >> now;
        now -= 1;
        a[i].l = now;
    }
    if ( n < 3) {
        cout << "NO";
        return 0;
    }
    for ( int i = 0; i < n; i++) {
        int A = i;
        int B = a[i].l;
        int C = a[a[i].l].l;
        if ( A != B && B != C && C != A && a[C].l == A) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}