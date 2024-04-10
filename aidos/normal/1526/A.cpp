#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
int a[maxn];
void solve(){
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int it = 0; it < 100; it++) {
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (i - 1 + n) % n;
            if(a[j] + a[k] == 2 * a[i]) {
                swap(a[i], a[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
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