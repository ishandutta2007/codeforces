#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    cin >> n;
    int x = 0;
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        x += a[i];
        s1 = max(s1, x);
    }
    cin >> k;
    x = 0;
    for(int i = 0; i < k; i++) {
        cin >> b[i];

        x += b[i];
        s2 = max(s2, x);
    }
    cout << s1 + s2 << "\n";
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