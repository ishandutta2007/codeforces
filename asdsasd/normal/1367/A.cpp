#include <bits/stdc++.h>
using namespace std;

void solve(){
    string b;
    cin >> b;
    string ans;
    ans += b[0];
    auto l = b.size();
    for(int i = 1; i < l; i+=2) ans += b[i];
    cout << ans << endl;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}