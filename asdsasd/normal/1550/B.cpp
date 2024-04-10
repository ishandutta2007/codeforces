#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<char> S(n);
    for(int i = 0; i < n; i++) cin >> S[i];
    int ans = a * n;
    if(b > 0){
        ans += b * n;
    }
    else{
        char bef = '2';
        int cnt = 0;
        for(auto s: S){
            if(s != bef){
                bef = s;
                cnt++;
            }
        }
        ans += (cnt + 2) / 2 * b;
    }
    cout << ans << "\n";
}

int main(void){
    int t;
    cin >> t;
    while(t--) solve();
}