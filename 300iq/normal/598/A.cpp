#include <bits/stdc++.h>

using namespace std;
int main(){
    long long t, n;
    long long c;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        c = ((1 + n) * n) / 2;
        for(long long k = 1; k <= n; k *= 2) {
            c -= k;
            c -= k;
        }
        cout << c << endl;
    }
}