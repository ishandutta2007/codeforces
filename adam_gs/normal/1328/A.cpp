#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        int p=1;
        int k=1000000000;
        int sr=(p+k)/2;
        while (p<k) {
            if (sr*b<a) {
                p=sr+1;
            } else {
                k=sr;
            }
            sr=(p+k)/2;
        }
        b*=sr;
        cout << b-a << '\n';
    }
}