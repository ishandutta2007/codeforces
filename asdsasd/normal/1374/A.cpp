#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    n -= y;
    n = n / x * x;
    cout << n + y << endl;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}