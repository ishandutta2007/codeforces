#include<iostream>
using namespace std;
int i, ff[11], u;
long long k, nr;
char s[] = "codeforces";
int main(){
    cin>> k;
    for(i = 0; i < 10; i++){
        ff[i] = 1;
    }
    u = 0;
    nr = 1;
    while(nr < k){
        ff[u]++;
        u++;
        if(u == 10){
            u = 0;
        }
        nr = 1;
        for(i = 0; i < 10; i++){
            nr *= ff[i];
        }
    }
    for(i = 0; i < 10; i++){
        for(int j = 1; j <= ff[i]; j++){
            cout<< s[i];
        }
    }
}