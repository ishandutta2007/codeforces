#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
    return y? gcd(y, x % y) : x;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    int g = v[0], m = v[0];
    for(int i = 1; i < n; i++) {
        cin >> v[i];
        g = gcd(g, v[i]);
        m = max(m, v[i]);
    }
    m /= g;
    cout << ((m - n) % 2? "Alice\n" : "Bob\n");
}