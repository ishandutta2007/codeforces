#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a;
    cin >> n;
    int one = 0;
    int two = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == 1) one++;
        else two++;
    }
    if(one % 2 == 1) cout << "NO" << endl;
    else if(one == 0 && two % 2 == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
    
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}