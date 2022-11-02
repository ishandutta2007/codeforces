#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];



void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a < c) cout << 1 << " ";
    else cout << -1 << " ";
    if(a * 1ll * b > c) cout << b << "\n";
    else cout << -1 << "\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}