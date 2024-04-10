#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector< pair<int, int> > ans;
    while(true) {
        int x = -1;
        int y = -1;
        for(int i =0; i < n; i++) {
            if(a[i] > b[i]) {
                x = i;
            } else if(a[i] < b[i]) {
                y = i;
            }
        }
        if(x == -1 && y == -1) {
            break;
        }
        if(x == -1) {
            cout << -1 << "\n";
            return;
        }
        if(y == -1) {
            cout << -1 << "\n";
            return;
        }
        a[x]--;
        a[y]++;
        ans.push_back({x+1, y+1});
    }
    cout << ans.size() << "\n";
    for(auto d: ans) {
        cout << d.first << " " << d.second << "\n";
    }
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