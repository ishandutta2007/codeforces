#include<iostream>
using namespace std;
int n, i, minim, x, nr;
int main(){
    cin>> n;
    minim = 55;
    for(i = 1; i <= n; i++){
        cin>> x;
        if(x < minim){
            minim = x;
            nr = 1;
        }
        else{
            if(x == minim){
                nr++;
            }
        }
    }
    if(nr <= n / 2){
        cout<<"Alice";
    }
    else{
        cout<<"Bob";
    }
}