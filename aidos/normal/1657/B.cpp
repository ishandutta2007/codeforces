#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    int B, x, y;
    cin >> n >> B >> x >> y;
    ll s = 0;
    ll c = 0;
    for(int i = 1; i <= n; i++) {
        if(c+x <= B) {
            c += x;
        } else c -= y;
        s += c;
    }
    cout << s << "\n";
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