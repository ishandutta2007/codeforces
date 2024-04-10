#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    cin >> n;
    vector<int> cnt(n+1, 0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while(x > n) {
            x /= 2;
        }
        cnt[x]++;
    }
    for(int i = n; i >= 1; i--) {
        if(cnt[i] == 0) {
            cout << "NO\n";
            return;
        }
        if(cnt[i] > 1) {
            cnt[i/2] += cnt[i] - 1;
        }
    }
    cout << "YES\n";

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