#include<iostream>
#include<cstring>
using namespace std;
int t, n, i;
int ff[200];
char val, s[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        ff['R'] = ff['S'] = ff['P'] = 0;
        for(i = 1; i <= n; i++){
            ff[ s[i] ]++;
        }
        if(ff['R'] >= max(ff['S'], ff['P']) ){
            val = 'P';
        }
        else{
            if(ff['S'] >= max(ff['R'], ff['P']) ){
                val = 'R';
            }
            else{
                val = 'S';
            }
        }
        for(i = 1; i <= n; i++){
            cout<< val;
        }
        cout<<"\n";
    }
}