#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    cin >> n;
    ll s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i == 0) s = x;
        else s &= x;
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