#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    cin >> n >> k;
    ll s = 0, t= 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        t += (x+k-1)/k;
    }
    cout << (s + k - 1)/k << " " << t << "\n";


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