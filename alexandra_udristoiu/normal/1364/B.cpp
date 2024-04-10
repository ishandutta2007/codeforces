#include<iostream>
using namespace std;
int n, i, k, t;
int v[100005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        k = 1;
        for(i = 2; i < n; i++){
            if( !(v[i] > v[k] && v[i] < v[i + 1]) && !(v[i] < v[k] && v[i] > v[i + 1]) ){
                v[++k] = v[i];
            }
        }
        v[++k] = v[n];
        cout<< k <<"\n";
        for(i = 1; i <= k; i++){
            cout<< v[i] <<" ";
        }
        cout<<"\n";
    }
}