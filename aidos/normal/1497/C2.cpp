#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 5e5 + 123;
const int mod = 1e9 + 7;
int n;
int k;
void solve() {
    cin >> n >> k;
    while(k > 3) {
        cout << 1 << " ";
        k--;
        n--;
    }
    if(n % 2 == 1) {
        cout << 1 << " " << n/2 << " " << n/2  << "\n";
        return;
    }
    if(n % 4 == 0) {
        cout << n/4 << " " << n/4 << " " << n/2 << "\n";
        return;
    }
    cout << 2 << " " << n/2 - 1 << " " << n/2-1 << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}