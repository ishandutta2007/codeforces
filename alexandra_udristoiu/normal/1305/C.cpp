#include<iostream>
using namespace std;
int n, m, i, j, sol;
int v[200005];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    if(n > m){
        cout<< 0;
        return 0;
    }
    sol = 1;
    for(i = 1; i < n; i++){
        for(j = i + 1; j <= n; j++){
            if(v[i] > v[j]){
                sol = sol * 1LL * (v[i] - v[j]) % m;
            }
            else{
                sol = sol * 1LL * (v[j] - v[i]) % m;
            }
        }
    }
    cout<< sol;
}