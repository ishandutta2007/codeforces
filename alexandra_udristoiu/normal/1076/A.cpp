#include<iostream>
using namespace std;
int n, i, p;
char s[200005];
int main(){
    cin>> n;
    cin>> s + 1;
    p = n;
    for(i = 1; i < n; i++){
        if(s[i] > s[i + 1]){
            p = i;
            break;
        }
    }
    for(i = 1; i <= n; i++){
        if(i != p){
            cout<< s[i];
        }
    }
}