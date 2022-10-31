#include<iostream>
#include<cstdio>
using namespace std;
int n, i, minim, sol;
int v[1000005];
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    minim = n - v[n];
    sol = 1;
    for(i = n - 1; i >= 1; i--){
        if(i < minim){
            sol++;
        }
        minim = min(minim, i - v[i]);
    }
    cout<< sol;
}