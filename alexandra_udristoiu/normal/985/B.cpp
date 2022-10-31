#include<iostream>
using namespace std;
int n, m, i, j, ok;
char c[2005][2005];
int ff[2005];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> c[i] + 1;
        for(j = 1; j <= m; j++){
            if(c[i][j] == '1'){
                ff[j]++;
            }
        }
    }
    for(i = 1; i <= n; i++){
        ok = 1;
        for(j = 1; j <= m; j++){
            if(c[i][j] == '1' && ff[j] == 1){
                ok = 0;
                break;
            }
        }
        if(ok == 1){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}