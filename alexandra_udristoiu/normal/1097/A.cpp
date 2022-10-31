#include<iostream>
using namespace std;
int i, ok;
char x, y, a, b;
int main(){
    cin>> x >> y;
    for(i = 1; i <= 5; i++){
        cin>> a >> b;
        if(a == x || b == y){
            ok = 1;
        }
    }
    if(ok == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}