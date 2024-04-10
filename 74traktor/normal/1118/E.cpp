#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    if (k * (k - 1) < n){
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    int p1 = 1, p2 = 2;
    for (int i = 1; i <= n / 2; ++i){
        cout << p1 << " " << p2 << '\n';
        cout << p2 << " " << p1 << '\n';
        p2++;
        if (p2 == k + 1){
            p1++;
            p2 = p1 + 1;
        }
    }
    if (n % 2 == 1)
        cout << p1 << " " << p2 << '\n';
    return 0;
}