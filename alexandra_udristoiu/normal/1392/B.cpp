#include<iostream>
using namespace std;
int t, n, i, maxim;
long long k;
int v[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        maxim = -1000000000;
        for(i = 1; i <= n; i++){
            cin>> v[i];
            maxim = max(maxim, v[i]);
        }
        for(i = 1; i <= n; i++){
            v[i] = maxim - v[i];
        }
        if(k % 2 == 0){
            maxim = 0;
            for(i = 1; i <= n; i++){
                maxim = max(maxim, v[i]);
            }
            for(i = 1; i <= n; i++){
                v[i] = maxim - v[i];
            }
        }
        for(i = 1; i <= n; i++){
            cout<< v[i] <<" ";
        }
        cout<<"\n";
    }
}