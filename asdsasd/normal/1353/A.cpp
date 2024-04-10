#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 1) cout << 0 << endl;
    else if(n == 2) cout << m << endl;
    else cout << 2 * m << endl;
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}