#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    int a, b;
    string s;
    cin >> n >> a >> b >> s;
    if(b >= 0) {
        cout << n * a + n * b << "\n";
        return;
    }
    int cur = 0;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) cnt++;
    }
    while(cnt > 2) {
        cnt -= 2;
        cur += b;
    }
    if(cnt == 2) cur += 2*b;
    else cur += b;
    cout << n * a + cur << "\n";
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