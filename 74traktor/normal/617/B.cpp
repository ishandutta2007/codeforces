#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[102];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0, kol = 0;
    bool f = false;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] == 1){
            if (f) ans *= kol;
            else f = true, ans = 1;
            kol = 1;
        }
        else kol++;
    }
    cout << ans << endl;
    return 0;
}