#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
int cnt[maxn];
int get(int a, int b, int c) {
    if(a > b && a>c) return 0;
    return max(b, c) - a + 1;
}
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << get(a, b, c) << " " << get(b, a, c) << " "<< get(c, a, b) << "\n";
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