#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
void solve(){
    cin >> n;
    if(n % 2 == 0) {
        cout << n/2 << " " << n/2-1 << " " << 1 << "\n";
        return;
    }
    for(int i = 3; i <= 100; i+=2) {
        if(__gcd(n-i-1, i)==1) {
            cout << n - i - 1 << " " << i << " " << 1 << "\n";
            return;
        }
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