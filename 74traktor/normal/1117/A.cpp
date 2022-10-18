#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int imax = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], imax = max(a[i], imax);
    int ans = 1, len = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] != a[i - 1]){
            if (a[i - 1] == imax) ans = max(ans, len);
            len = 1;
        }
        else len++;
    }
    if (a[n] == imax) ans = max(ans, len);
    cout << ans << endl;
    return 0;
}