#include <bits/stdc++.h>
using namespace std;
char bd[10][30];
int n,m,k;
char get(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m) return '.';
    return bd[x][y];
}
void check(int x, int y){
    if(bd[x][y] == '.') return;
    for(int i=1;i<=k;i++){
        if(get(x-i,y-i)=='.' || get(x-i,y+i)=='.') return;
    }
    bd[x][y] = '#';
    for(int i=1;;i++){
        if(get(x-i,y-i)=='.' || get(x-i,y+i)=='.') return;
        bd[x-i][y-i] = bd[x-i][y+i] = '#';
    }
}
void solve(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> bd[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check(i,j);
        }
    }
    // for(int i=0;i<n;i++) cout << bd[i] << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(bd[i][j] == '*'){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}