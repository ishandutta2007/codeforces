#include <bits/stdc++.h>

using namespace std;

#define int long long

int x[300005];
int t[300005];

int gcd(int a, int b){
    while (a > 0 && b > 0){
        int p = a % b;
        a = b;
        b = p;
    }
    return a + b;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> x[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> t[i];
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) ans = gcd(ans, x[i] - x[i - 1]);
    for (int i = 1; i <= m; ++i){
        if (ans % t[i] == 0){
            cout << "YES" << '\n';
            cout << x[1] << " " << i << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}