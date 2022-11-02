#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, m, rd, cd, r, c;
int rec(int r, int c, int dr, int dc) {
    if(r==rd || c==cd) {
        return 0;
    }
    if(c + dc < 1 || c + dc > m) dc *= -1;
    if(r + dr < 1 || r + dr > n) dr *= -1;
    return rec(r + dr, c + dc, dr, dc) + 1;
}
void solve(){
    cin >> n >> m >> r >> c >> rd >> cd;
    cout<<rec(r, c, 1, 1) << "\n";
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