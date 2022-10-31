#include<iostream>
using namespace std;
int n, i, sol, sum, p;
char s[1000005];
int main(){
    cin>> n;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        if(s[i] == '('){
            sum++;
        }
        else{
            sum--;
        }
    }
    if(sum != 0){
        cout<< -1;
        return 0;
    }
    sum = 0;
    p = -1;
    for(i = 1; i <= n; i++){
        if(s[i] == '('){
            sum++;
        }
        else{
            sum--;
        }
        if(sum < 0 && p == -1){
            p = i;
        }
        if(sum == 0 && p != -1){
            sol += i - p + 1;
            p = -1;
        }
    }
    cout<< sol;
}