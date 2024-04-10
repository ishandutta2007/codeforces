#include <bits/stdc++.h>

using namespace std;


int main () {
    long long n, w;
    cin >> n >> w;
    vector <long long> a(n);
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long minp = 0;
    long long maxp = 0;
    long long now = 0;
    for ( int i = 0; i < n; i++) {
        now += a[i];
        if ( now > maxp) {
            maxp = now;
        }
        if ( now < minp) {
            minp = now;
        }
    }

    if ( minp < 0) {
        minp *= -1;
    }
    else {
        minp = 0;
    }

    maxp = w - maxp;
    if ( minp > maxp) {
        cout << 0;
        return 0;
    }

    cout << maxp - minp + 1;








    return 0;
}