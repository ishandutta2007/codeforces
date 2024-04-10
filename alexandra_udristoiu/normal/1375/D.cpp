#include<iostream>
using namespace std;
int t, n, i, k, x, j, ok;
int v[1005], ff[1005], sol[2005];
int mex(){
    for(int i = 0; i <= n; i++){
        ff[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        ff[ v[i] ] = 1;
    }
    for(int i = 0; i <= n; i++){
        if(ff[i] == 0){
            return i;
        }
    }
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        k = 0;
        while(1){
            x = mex();
            if(x < n){
                sol[++k] = x + 1;
                v[x + 1] = x;
            }
            else{
                for(i = 1; i <= n; i++){
                    if(v[i] != i - 1){
                        for(j = 1; j <= n; j++){
                            if(v[j] == i - 1){
                                sol[++k] = j;
                                v[j] = n;
                                sol[++k] = i;
                                v[i] = i - 1;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            ok = 1;
            for(i = 1; i <= n; i++){
                if(v[i] != i - 1){
                    ok = 0;
                    break;
                }
            }
            if(ok == 1){
                break;
            }
        }
        cout<< k <<"\n";
        for(i = 1; i <= k; i++){
            cout<< sol[i] <<" ";
        }
        cout<<"\n";
    }
}