#include <bits/stdc++.h>

using namespace std;

//#define int long long

main(){
    //freopen("input.txt", "r");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int cnt = (n - k) / 2;
    int i = 1, cnt1 = cnt;
    while (i <= n){
        if (cnt1 == 0){
            cout << 1;
            cnt1 = cnt;
        }
        else{
            cout << 0;
            cnt1--;
        }
        ++i;
    }
    return 0;
}