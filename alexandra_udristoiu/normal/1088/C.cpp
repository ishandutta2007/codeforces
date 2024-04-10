#include<iostream>
using namespace std;
int n, i, j, x;
int v[2005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    cout<< n + 1 <<"\n";
    for(i = n; i >= 1; i--){
        for(x = 0; x <= 2001; x++){
            if( (v[i] + x) % 2001 == i ){
                break;
            }
        }
        cout<<"1 "<< i <<" "<< x <<"\n";
        for(j = 1; j <= i; j++){
            v[j] += x;
        }
    }
    cout<<"2 "<< n <<" 2001";
}