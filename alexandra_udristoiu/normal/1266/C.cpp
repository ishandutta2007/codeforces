#include<iostream>
using namespace std;
int n, m, i, j;
int a[505][505], b[1005];
int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    cin>> n >> m;
    if(n == 1 && m == 1){
        cout<< 0;
        return 0;
    }
    if(m == 1){
        for(i = 1; i <= n; i++){
            cout<< i + 1 <<"\n";
        }
        return 0;
    }
    for(i = 1; i <= n + m; i++){
        b[i] = i;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            a[i][j] = b[i];
        }
    }
    for(j = 1; j <= m; j++){
        for(i = 1; i <= n; i++){
            a[i][j] *= b[j + n] / cmmdc(b[j + n], a[i][j]);
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout<< a[i][j] <<" ";
        }
        cout<<"\n";
    }
}