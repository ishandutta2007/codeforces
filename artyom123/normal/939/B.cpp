#include <bits/stdc++.h>

using namespace std;

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n;
    int k;
    cin >> k;
    vector <long long> a(k);
    for ( int i = 0; i < k; i++) {
        cin >> a[i];
    }
    long long best = 1000000000000000000 + 1;
    int type = 0;
    long long d = 0;
    for ( int i = 0;  i < k; i++) {
        if ( n % a[i] < best) {
            best = n % a[i];
            type = i + 1;
            d = n / a[i];
        }
    }
    cout << type << " " << d;
    return 0;
}