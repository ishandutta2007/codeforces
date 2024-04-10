#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> k >> x;
        cout << x + 9 * (k - 1) << endl;
    }
    return 0;
}