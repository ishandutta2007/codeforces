#include<iostream>
using namespace std;
int t, n, i, nr, ii;
int v[100005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        for(ii = 30; ii >= 0; ii--){
            nr = 0;
            for(i = 1; i <= n; i++){
                nr += ( (v[i] >> ii) & 1);
            }
            if(nr % 2 == 1){
                if(nr % 4 == 1 || (n - nr) % 2 == 1){
                    cout<<"WIN\n";
                }
                else{
                    cout<<"LOSE\n";
                }
                break;
            }
        }
        if(ii == -1){
            cout<<"DRAW\n";
        }
    }
}