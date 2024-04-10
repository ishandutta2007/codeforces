#include<iostream>
using namespace std;
int n, i, t, ok;
char s[105];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> s + 1;
        ok = 0;
        for(i = 1; i <= n - 10; i++){
            if(s[i] == '8'){
                ok = 1;
                break;
            }
        }
        if(ok == 1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}