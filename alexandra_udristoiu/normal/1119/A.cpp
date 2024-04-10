#include<iostream>
using namespace std;
int n, i, maxim;
int v[300005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n; i++){
        if(v[i] != v[n]){
            maxim = max(maxim, n - i);
            break;
        }
    }
    for(i = n; i >= 1; i--){
        if(v[1] != v[i]){
            maxim = max(maxim, i - 1);
            break;
        }
    }
    cout<< maxim;
}