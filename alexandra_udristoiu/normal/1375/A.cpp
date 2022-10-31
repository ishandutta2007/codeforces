#include<iostream>
using namespace std;
int n, t, i, v[105];
int modul(int x){
    if(x > 0){
        return x;
    }
    return -x;
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        for(i = 1; i <= n; i++){
            if(i % 2 == 1){
                cout<< modul(v[i]) <<" ";
            }
            else{
                cout<< -modul(v[i]) <<" ";
            }
        }
        cout<<"\n";
    }
}