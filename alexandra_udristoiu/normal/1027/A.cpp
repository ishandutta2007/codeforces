#include<iostream>
using namespace std;
int n, i, ok, t;
char s[105];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> s + 1;
        ok = 1;
        for(i = 1; i <= n / 2; i++){
            if(s[i] - s[n - i + 1] > 2 || s[i] - s[n - i + 1] < -2){
                ok = 0;
                break;
            }
            if(s[i] - s[n - i + 1] == 1 || s[i] - s[n - i + 1] == -1){
                ok = 0;
                break;
            }
        }
        if(ok == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}