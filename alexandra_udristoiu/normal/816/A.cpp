#include<iostream>
using namespace std;
int sol, x, y, i, j, a, b, aux;
char s[7];
int main(){
    cin>> s;
    x =  ( (s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
    sol = 1000000;
    for(i = 0; i < 24; i++){
        for(j = 0; j < 60; j++){
            s[0] = i / 10;
            s[1] = i % 10;
            s[2] = j / 10;
            s[3] = j % 10;
            if(s[0] == s[3] && s[1] == s[2]){
                y = i * 60 + j;
                if(y < x){
                    y += 24 * 60;
                }
                if(y - x < sol){
                    sol = y - x;
                }
            }
        }
    }
    cout<< sol;
    return 0;
}