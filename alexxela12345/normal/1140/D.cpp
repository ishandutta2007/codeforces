#include <bits/stdc++.h>
#define _ << " " <<
#define int long long

using namespace std;

main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 3; i <= n; i++) {
        ans += i * (i - 1);
    }
    cout << ans << endl;


    return 0;
}