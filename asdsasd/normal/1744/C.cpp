#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/fenwicktree>
using namespace std;
// using namespace atcoder;

void solve(){
    int n;
    char c;
    cin >> n >> c;
    string S;
    cin >> S;
    if(c == 'g'){
        cout << 0 << "\n";
        return;
    }
    S = S + S;
    int ans = 0;
    int bef = 1 << 30;
    for(int i = 0; i < 2 * n; i++){
        if(S[i] == c){
            if(bef == 1 << 30) bef = i;
        }
        else if(S[i] == 'g'){
            ans = max(ans, i - bef);
            bef = 1 << 30;
        }
            
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}