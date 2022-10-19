#include <bits/stdc++.h>
using namespace std;

void solve(){
    int w, h, n;
    cin >> w >> h >> n;
    int cnt = 1;
    while(w % 2 == 0){
        cnt *= 2;
        w /= 2;
    }
    while(h % 2 == 0){
        cnt *= 2;
        h /= 2;
    }
    if(cnt >= n) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}