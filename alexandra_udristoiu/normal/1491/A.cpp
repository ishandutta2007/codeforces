#include<iostream>
using namespace std;
int n, i, q, x, nr1, t;
int v[100005];
int main(){
    cin>> n >> q;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        nr1+= v[i];
    }
    for(; q; q--){
        cin>> t >> x;
        if(t == 1){
            nr1 -= v[x];
            v[x] = 1 - v[x];
            nr1 += v[x];
        }
        else{
            if(nr1 >= x){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
    }
}