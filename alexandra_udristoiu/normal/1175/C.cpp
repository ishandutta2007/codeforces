#include<iostream>
using namespace std;
int t, n, i, x, minim, k, val;
int v[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        x = 0;
        minim = v[k + 1];
        for(i = 1; i <= n - k; i++){
            val = (v[i] + v[i + k]) / 2;
            if(minim > max(val - v[i], v[i + k] - val) ){
                x = val;
                minim = max(val - v[i], v[i + k] - val);
            }
        }
        cout<< x <<"\n";
    }
}