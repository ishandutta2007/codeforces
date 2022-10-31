#include<iostream>
using namespace std;
int n, t, i, nr, ok, minim, ii;
char a[100005], b[100005];
int ff[200];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> a + 1;
        cin>> b + 1;
        ok = 1;
        nr = 0;
        for(i = 1; i <= n; i++){
            if(a[i] > b[i]){
                ok = 0;
            }
        }
        for(ii = 'a'; ii <= 't'; ii++){
            minim = 'z';
            for(i = 1; i <= n; i++){
                if(a[i] == ii && b[i] != ii){
                    minim = min(minim, (int) b[i]);
                }
            }
            if(minim != 'z'){
                nr++;
                for(i = 1; i <= n; i++){
                    if(a[i] == ii && b[i] != ii){
                       a[i] = minim;
                    }
                }
            }
        }
        if(ok == 0){
            nr = -1;
        }
        cout<< nr <<"\n";
    }
}