#include<iostream>
using namespace std;
int t, n, i;
long long sol;
int v[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        sol = 0;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        for(i = n - 1; i >= 1; i--){
            if(v[i] > v[i + 1]){
                sol += v[i] - v[i + 1];
            }
        }
        cout<< sol <<"\n";
    }
}