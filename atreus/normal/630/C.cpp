#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans += (1ll << i);
    }
    cout << ans << endl;
}