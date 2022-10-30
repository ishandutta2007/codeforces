#include<iostream>
using namespace std;
int n, i, nr, ii, p, m, j;
int v[60], w[60], v2[60];
int a[60][60];
void solve(){
    int i, j, u = n;
    if(nr != 1){
        a[++m][1] = nr;
        for(i = 1; i <= nr; i++){
            a[m][i + 1] = w[i];
        }
    }
    for(i = 1; i <= nr; i++){
        w[i] += w[i - 1];
        for(j = w[i]; j > w[i - 1]; j--){
            v2[u--] = v[j];
        }
    }
    for(i = 1; i <= n; i++){
        v[i] = v2[i];
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(ii = 0; ii + 2 <= n; ii += 2){
        for(i = 1; i <= n; i++){
            if(v[i] == ii + 1){
                p = i;
                break;
            }
        }
        nr = 0;
        for(i = 1; i <= ii; i++){
            w[++nr] = 1;
        }
        w[++nr] = p - ii;
        if(n != p){
            w[++nr] = n - p;
        }
        solve();
        for(i = 1; i <= n; i++){
            if(v[i] == ii + 2){
                p = i;
                break;
            }
        }
        nr = 0;
        if(p != 1){
            w[++nr] = p - 1;
        }
        w[++nr] = (n - ii) - p;
        for(i = 1; i <= ii + 1; i++){
            w[++nr] = 1;
        }
        solve();
    }
    /*for(i = 1; i <= n; i++){
        cout<< v[i] <<" ";
    }*/

    cout<< m <<"\n";
    for(i = 1; i <= m; i++){
        for(j = 1; j <= a[i][1] + 1; j++){
            cout<< a[i][j] <<" ";
        }
        cout<<"\n";
    }
}