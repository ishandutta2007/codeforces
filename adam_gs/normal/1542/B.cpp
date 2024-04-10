#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll akt=1;
    while(akt<=n) {
        if((n-akt)%b==0) {
            cout << "YES\n";
            return;
        }
        akt*=a;
        if(a==1) break;
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int _;
    cin >> _;
    while(_--) solve();
}