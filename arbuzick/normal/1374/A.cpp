#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x, y, n;
        cin >> x >> y >> n;
        int k = n / x * x;
        if(k + y > n)
            k -= x;
        cout << k + y << "\n";
    }
    return 0;
}