#include <bits/stdc++.h>

using namespace std;

int a[100005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    bool f = true;
    for (int i = 1; i <= n; ++i){
        if (a[i] % 2 != a[1] % 2) f = false;
    }
    if (f){
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    }
    else{
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    }
    return 0;
}