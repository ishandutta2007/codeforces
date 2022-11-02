#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int get(int x) {
    if(x % 4 == 3) return 0;
    if(x % 4 == 1) return 1;
    if(x % 4 == 0) return x;
    return x^1;
}
void solve(){
    cin >> n >> k;
    if(get(n-1) == k) {
        cout << n << "\n";
    } else if((get(n-1)^k) != n) {
        cout << n + 1 << "\n";
    } else {
        cout << n + 2 << "\n";
    }
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