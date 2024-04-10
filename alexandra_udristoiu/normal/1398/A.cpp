#include<iostream>
using namespace std;
int n, t, i;
int v[50005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        if(v[1] + v[2] > v[n]){
            cout<<"-1\n";
        }
        else{
            cout<<"1 2 "<< n <<"\n";
        }
    }
}