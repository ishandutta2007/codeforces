#include <iostream>
#include <vector>

using namespace std;

int main() {
    long int n, a, b, c, d, sum = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d >> n;
    vector<bool> hit(n, false);
    for(int i = a-1; i < n; i += a) {
        hit[i] = true;
    }
    for(int i = b-1; i < n; i += b) {
        hit[i] = true;
    }
    for(int i = c-1; i < n; i += c) {
        hit[i] = true;
    }
    for(int i = d-1; i < n; i += d) {
        hit[i] = true;
    }
    for(int i = 0; i < n; i ++) {
        if(hit[i]) {
            sum ++;
        }
    }
    cout << sum;
    return 0;
}