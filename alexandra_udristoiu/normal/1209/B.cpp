#include<iostream>
using namespace std;
int n, i, ii, nr, sol;
int a[105], b[105];
char s[105];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> s[i];
        s[i] -= '0';
        sol += s[i];
    }
    for(i = 1; i <= n; i++){
        cin>> a[i] >> b[i];
    }
    for(ii = 1; ii <= 10000; ii++){
        nr = 0;
        for(i = 1; i <= n; i++){
            if(ii >= b[i] && (ii - b[i]) % a[i] == 0){
                s[i] = 1 - s[i];
            }
            nr += s[i];
        }
        sol = max(sol, nr);
    }
    cout<< sol;
}