#include<iostream>
using namespace std;
int n, i, ii, nr, ok;
char s[100005];
int main(){
    cin>> n;
    cin>> s + 1;
    if(n == 1){
        cout<<"Yes";
        return 0;
    }
    for(ii = 'a'; ii <= 'z'; ii++){
        nr = 0;
        for(i = 1; i <= n; i++){
            if(s[i] == ii){
                nr++;
            }
        }
        if(nr >= 2){
            ok = 1;
            break;
        }
    }
    if(ok == 1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}