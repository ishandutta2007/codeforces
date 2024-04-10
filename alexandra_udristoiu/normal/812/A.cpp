#include<iostream>
using namespace std;
int i, l, s, r;
int ok[5], ok2[5];
int main(){
    for(i = 0; i < 4; i++){
        cin>> l >> s >> r >> ok[i];
        if(l + s + r != 0){
            ok2[i] = 1;
            if(l == 1){
                ok2[ (i - 1 + 4) % 4] = 1;
            }
            if(s == 1){
                ok2[ (i + 2) % 4] = 1;
            }
            if(r == 1){
                ok2[ (i + 1) % 4] = 1;
            }
        }
    }
    for(i = 0; i < 4; i++){
        if(ok[i] + ok2[i] == 2){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}