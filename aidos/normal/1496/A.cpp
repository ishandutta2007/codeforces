#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    string s;
    cin >> n >> k >> s;
    for(int i = 0; i < k; i++) {
        if(s[i] != s[n-i-1]) {
            cout << "NO\n";
            return;
        }
    }
    if(n % 2==0 && n/2 == k) {
        cout << "NO\n";
    } else cout << "YES\n";
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