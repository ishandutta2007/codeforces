#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];



void solve(){
    int n;
    cin >> n;
    int c = -1;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x + 1 <= c) {
            continue;
        }
        if(c == x) {
            x++;
        }
        c = x;
        ans++;
    }
    cout << ans<<"\n";
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