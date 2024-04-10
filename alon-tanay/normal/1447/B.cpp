#include <iostream>

using namespace std;

int main() {
    int t, n, m, a, min_a;
    long int sum;
    bool odd;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        odd = false;
        sum = 0;
        min_a = 100;
        cin >> n >> m;
        for(int j = 0; j < n*m; j ++) {
            cin >> a;
            if(a < 0) {
                a = -a;
                odd = !odd;
            }
            if(a < min_a) {
                min_a = a;
            }
            sum += a;
        }
        cout << (odd ? (sum - 2*min_a) : sum) << endl;
    }
    return 0;
}