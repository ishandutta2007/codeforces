#include<iostream>
using namespace std;
int ii, n;
char s[1000005];
struct str{
    char t[3];
};
str r;
str solve();
str termen();
int calc(int i, int j, char semn){
    if(semn == '|'){
        return (i | j);
    }
    if(semn == '&'){
        return (i & j);
    }
    if(semn == '^'){
        return (i ^ j);
    }
}
str solve(){
    str x = termen();
    while(s[ii] == '|' || s[ii] == '&' || s[ii] == '^'){
        char semn = s[ii];
        ii++;
        str y = termen();
        str aux = {0, 0, 0};
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(x.t[i] == 1 && y.t[j] == 1){
                    aux.t[ calc(i, j, semn) ] = 1;
                }
            }
        }
        if(x.t[2] == 1){
            for(int i = 0; i < 2; i++){
                if(y.t[i] == 1){
                    if(calc(0, i, semn) != calc(1, i, semn) ){
                        aux.t[2] = 1;
                    }
                    else{
                        aux.t[ calc(0, i, semn) ] = 1;
                    }
                }
            }
        }
        if(y.t[2] == 1){
            for(int i = 0; i < 2; i++){
                if(x.t[i] == 1){
                    if(calc(0, i, semn) != calc(1, i, semn) ){
                        aux.t[2] = 1;
                    }
                    else{
                        aux.t[ calc(0, i, semn) ] = 1;
                    }
                }
            }
        }
        if(x.t[2] == 1 && y.t[2] == 1){
            aux.t[0] = aux.t[1] = 1;
        }
        if(semn != '^' && x.t[2] == 1 && y.t[2] == 1){
            aux.t[2] = 1;
        }
        x = aux;
    }
    return x;
}
str termen(){
    str x = {0, 0, 0};
    if(s[ii] == '('){
        ii++;
        x = solve();
        ii++;
    }
    else{
        if(s[ii] == '?'){
            x.t[2] = 1;
        }
        else{
            x.t[ s[ii] - '0' ] = 1;
        }
        ii++;
    }
    return x;
}
int main(){
    cin>> n;
    cin>> s;
    r = solve();
    if(r.t[2] == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}