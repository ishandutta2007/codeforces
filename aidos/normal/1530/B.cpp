#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
int get(int x) {
    if(x <= 2) return 0;
    x -= 2;
    return (x + 1)/2;
}

void solve(){
    int h, w;
    cin >> h >> w;
    vector<string> ans(h, string(w, '0'));
    ans[0][0] = '1';
    ans[0][w-1] = '1';
    ans[h-1][0] = '1';
    ans[h-1][w-1] = '1';
    for(int i = 2; i + 1 < w - 1; i += 2) {
        ans[0][i] = '1';
        ans[h-1][i] = '1';
    }
    for(int i = 2; i + 1 < h - 1; i += 2) {
        ans[i][0] = '1';
        ans[i][w-1] = '1';
    }
    for(auto x: ans) {
        cout << x<<"\n";
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