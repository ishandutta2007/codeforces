#include<iostream>
using namespace std;
int t, n, i, j, ok, nr, m, dir, iv, jv;
int a[305][305];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> m;
        ok = 1;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                cin>> a[i][j];
            }
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                nr = 0;
                for(dir = 0; dir < 4; dir++){
                    iv = i + di[dir];
                    jv = j + dj[dir];
                    if(iv >= 1 && iv <= n && jv >= 1 && jv <= m){
                        nr++;
                    }
                }
                if(a[i][j] > nr){
                    ok = 0;
                }
                else{
                    a[i][j] = nr;
                }
            }
        }
        if(ok == 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
             for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                cout<< a[i][j] <<" ";
            }
            cout<<"\n";
        }
        }
    }
}