#include<iostream>
using namespace std;
int n, i, x, y, ok;
int g[100005];
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        g[x]++;
        g[y]++;
    }
    ok = 1;
    for(i = 1; i <= n; i++){
        if(g[i] == 2){
            ok = 0;
        }
    }
    if(ok == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}