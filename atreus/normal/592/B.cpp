#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll ans = (n - 1) * (n - 3);
    ans ++;
    cout << ans << endl;
    return 0;
}