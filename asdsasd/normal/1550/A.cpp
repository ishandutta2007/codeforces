#include <bits/stdc++.h>
using namespace std;

void solve(){
    int s;
    cin >> s;
    int ans = 0;
    int x = 1;
    while(s > 0){
        s -= x;
        x += 2;
        ans += 1;
    }
    cout << ans << "\n";
}

int main(void){
    int t;
    cin >> t;
    while(t--) solve();
}