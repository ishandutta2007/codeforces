#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int m=0;
        if (c!=0) {
            m=max(m, c*b);
        }
        if (d!=0) {
            m=max(m, d*a);
        }
        if (c!=a-1){
            m=max(m,(a-c-1)*b);
        }
        if (d!=b-1) {
            m=max(m,(b-d-1)*a);
        }
        cout << m << '\n';
    }
}