#include<iostream>
using namespace std;
int n, i, t, x, y, z;
int v[1005], ff[1005], maxim[1005], minim[1005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
            ff[ v[i] ] = i;
        }
        minim[n] = v[n];
        maxim[n] = 0;
        x = y = z = 0;
        for(i = n - 1; i >= 1; i--){
            minim[i] = min(v[i], minim[i + 1]);
            maxim[i] = maxim[i + 1];
            if(v[i] > minim[i + 1]){
                maxim[i] = max(maxim[i], v[i]);
            }
            if(v[i] < maxim[i]){
                x = i;
                y = ff[ maxim[i] ];
                z = ff[ minim[y] ];
            }
        }
        if(x == 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n"<< x <<" "<< y <<" "<< z <<"\n";
        }
    }
}