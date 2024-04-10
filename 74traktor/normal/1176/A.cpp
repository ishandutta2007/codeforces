#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> n;
        int a = 0, b = 0, c = 0;
        while (n % 2 == 0){
            a++;
            n /= 2;
        }
        while (n % 5 == 0){
            b++;
            n /= 5;
        }
        while (n % 3 == 0){
            c++;
            n /= 3;
        }
        if (n != 1) cout << -1 << '\n';
        else cout << 3 * b + 2 * c + a << '\n';
    }
    return 0;
}