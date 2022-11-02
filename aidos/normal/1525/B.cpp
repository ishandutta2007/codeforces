#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == i) cnt++;
    }
    if(cnt == n) {
        cout << 0 << "\n";
    } else if(a[1] == 1 || a[n] == n) {
        cout << 1 << "\n";
    } else if(a[1] != n || a[n] != 1){
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
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