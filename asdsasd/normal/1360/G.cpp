#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n * a != m * b){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int pos = 0;
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a; j++){
            ans[i][pos] = 1;
            pos++;
            if(pos == m) pos = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}