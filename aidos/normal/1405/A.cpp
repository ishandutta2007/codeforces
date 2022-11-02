#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    reverse(a, a + n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

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