#include<iostream>
using namespace std;
int n, i, j;
int v[20], d[20][370];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    d[0][0] = 1;
    for(i = 1; i <= n; i++){
        for(j = 0; j < 360; j++){
            if(d[i - 1][ (j + v[i]) % 360 ] == 1){
                d[i][j] = 1;
            }
            if(d[i - 1][ (j - v[i] + 360) % 360 ] == 1){
                d[i][j] = 1;
            }
        }
    }
    if(d[n][0] == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}