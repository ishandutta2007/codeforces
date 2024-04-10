#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

void output(ll num, ll denom) {
    ll d = __gcd(num, denom);
    cout << num / d << '/' << denom / d << endl;
}

int main() {
    ll T, W, B;
    cin >> T >> W >> B;
    ll g = __gcd(W, B);
    ll tmp = W / g;
    if (T / tmp < B) {
        output(min(T, min(W, B) - 1), T);
        return 0;
    }
    ll lcm = tmp * B;
    output(T / lcm * min(W, B) + min(T % lcm + 1, min(W, B)) - 1, T);
    return 0;
}