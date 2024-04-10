#include<iostream>
using namespace std;
int n, i, nr, nr1, nr2, x;
int v[200005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        if(x == 1){
            nr1++;
        }
        else{
            nr2++;
        }
    }
    if(nr1 >= 3){
        nr1 -= 3;
        v[1] = v[2] = v[3] = 1;
        nr = 3;
    }
    else{
        if(nr1 >= 1 && nr2 >= 1){
            nr1--;
            nr2--;
            nr = 2;
            v[1] = 2;
            v[2] = 1;
        }
    }
    for(i = 1; i <= nr2; i++){
        v[++nr] = 2;
    }
    for(i = 1; i <= nr1; i++){
        v[++nr] = 1;
    }
    for(i = 1; i <= nr; i++){
        cout<< v[i] <<" ";
    }
}