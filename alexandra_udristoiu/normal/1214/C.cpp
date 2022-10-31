#include<iostream>
using namespace std;
int n, i, p, sum, ok;
char s[200005];
int main(){
    cin>> n;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        if(s[i] == ')'){
            p = i;
            break;
        }
    }
    if(p == 0){
        cout<<"No";
        return 0;
    }
    for(i = p + 1; i <= n; i++){
        s[i - 1] = s[i];
    }
    s[n] = ')';
    ok = 1;
    for(i = 1; i <= n; i++){
        if(s[i] == '('){
            sum++;
        }
        else{
            sum--;
        }
        if(sum < 0){
            ok = 0;
        }
    }
    if(sum != 0){
        ok = 0;
    }
    if(ok == 1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}