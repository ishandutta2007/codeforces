#include<iostream>
using namespace std;
int n, i, x;
int v[200005];
long long sol;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    x = sol = v[n];
    for(i = n - 1; i >= 1; i--){
        x = min(x - 1, v[i]);
        x = max(0, x);
        sol += x;
    }
    cout<< sol;
}