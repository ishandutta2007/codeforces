#include<iostream>
using namespace std;
int n, i;
long long sol;
char s[70000];
int main(){
    cin>> n;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        if( (s[i] - '0') % 2 == 0){
            sol += i;
        }
    }
    cout<< sol;
}