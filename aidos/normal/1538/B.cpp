#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
int a[maxn];
void solve(){
    cin >> n;
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if(s % n != 0) {
        cout << -1 << "\n";
        return;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > s/n) cnt++;
    }
    cout << cnt <<"\n";
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}