#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(grid[i][j] == '1'){
                if(grid[i + 1][j] == '0' && grid[i][j + 1] == '0'){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}