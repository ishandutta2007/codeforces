#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        ll n, m, k;
        cin >> n >> m >> k;
        if(k < max(n, m))
            cout << "-1\n";
        else 
            cout << k - (n%2!=k%2) - (m%2!=k%2) << "\n";
    }
}