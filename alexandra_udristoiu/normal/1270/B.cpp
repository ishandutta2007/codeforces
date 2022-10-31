#include<iostream>
using namespace std;
int n, i, t, ok, ind;
int v[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        ok = 0;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        for(i = 1; i < n; i++){
            if(v[i] - v[i + 1] > 1 || v[i] - v[i + 1] < -1){
                ok = 1;
                ind = i;
                break;
            }
        }
        if(ok == 1){
            cout<<"YES\n"<< ind <<" "<< ind + 1 <<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}