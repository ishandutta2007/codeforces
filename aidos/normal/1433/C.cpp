#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = *max_element(a, a + n);
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            if(i > 0 && a[i-1] != x) {
                cout << i + 1 << "\n";
                return;
            }
            if(i < n-1 && a[i+1] != x) {
                cout << i + 1 << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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