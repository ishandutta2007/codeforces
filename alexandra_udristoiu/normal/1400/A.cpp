#include<iostream>
using namespace std;
int n, i, t;
char s[205], sol[205];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> s + 1;
        for(i = 1; i <= n; i++){
            sol[i] = s[2 * i - 1];
        }
        sol[n + 1] = 0;
        cout<< sol + 1 <<"\n";
    }
}