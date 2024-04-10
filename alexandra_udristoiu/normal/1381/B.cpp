#include<iostream>
using namespace std;
int n, t, i, k, j;
int v[4005], w[4005], d[2005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n + n; i++){
            cin>> v[i];
        }
        k = 1;
        w[1] = 1;
        for(i = 2; i <= n + n; i++){
            if(v[i] > v[ w[k] ]){
                w[++k] = i;
            }
        }
        for(i = 1; i < k; i++){
            w[i] = w[i + 1] - w[i];
        }
        w[k] = 2 * n - w[k] + 1;
        for(i = 1; i <= n; i++){
            d[i] = 0;
        }
        d[0] = 1;
        for(i = 1; i <= k; i++){
            for(j = n - w[i]; j >= 0; j--){
                if(d[j] == 1){
                    d[j + w[i] ] = 1;
                }
            }
        }
        if(d[n] == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}