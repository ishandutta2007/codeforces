#include<iostream>
using namespace std;
int m, n, i, j, ii, ok;
int v[52][10005], ff[10005], nr[52];
int main(){
    cin>> m >> n;
    for(i = 1; i <= m; i++){
        cin>> nr[i];
        for(j = 1; j <= nr[i]; j++){
            cin>> v[i][j];
        }
    }
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            ff[j] = 2;
        }
        for(j = 1; j <= nr[i]; j++){
            ff[ v[i][j] ] = 0;
        }
        for(ii = 1; ii <= m; ii++){
            ok = 1;
            for(j = 1; j <= nr[ii]; j++){
                if(ff[ v[ii][j] ] == 0){
                    ok = 0;
                    break;
                }
            }
            if(ok == 1){
                break;
            }
        }
        if(ii <= m){
            cout<<"impossible";
            return 0;
        }
    }
    cout<<"possible";
}