#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a)

using namespace std;

typedef long long ll;

const int N = 1e5;

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll tmp = y - n + 1;
    if (tmp <= 0) {
        cout << -1;
        return 0;
    }
    if (n - 1 + tmp * tmp < x) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
        cout << 1 << " ";
    cout << tmp;
}