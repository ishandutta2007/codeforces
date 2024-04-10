#include<iostream>
using namespace std;
int n, i, t, v[300005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        if(v[1] < v[n]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}