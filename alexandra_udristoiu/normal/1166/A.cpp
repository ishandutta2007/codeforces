#include<iostream>
using namespace std;
int n, i, sol;
int ff[200];
char s[25];
int solve(int n){
    return n * (n - 1) / 2;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> s;
        ff[ s[0] ]++;
    }
    for(i = 'a'; i <= 'z'; i++){
        sol += solve(ff[i] / 2);
        sol += solve(ff[i] - ff[i] / 2);
    }
    cout<< sol;
}