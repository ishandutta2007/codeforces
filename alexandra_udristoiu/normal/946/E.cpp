#include<iostream>
#include<cstring>
#define DIM 200005
using namespace std;
int t, n, i, j, ok, nr;
int nxt[DIM], ff[15];
char s[DIM];
int verif(int p){
    int i, j, nr = 0, o[12];
    for(i = 0; i <= 9; i++){
        if(ff[i] % 2 == 1){
            nr++;
            o[i] = 1;
        }
        else{
            o[i] = 0;
        }
    }
    if(p == n){
        return 1;
    }
    if(nxt[p + 1] < n - nr + 1){
        return 1;
    }
    if(nr > n - p){
        return 0;
    }
    for(i = n - nr + 1; i <= n; i++){
        for(j = s[i] - 1; j >= 0; j--){
            if(o[j] == 1){
                return 1;
            }
        }
        if(o[ s[i] ] == 1){
            o[ s[i] ] = 0;
        }
        else{
            return 0;
        }
    }
    return 0;
}
int verif2(int p){
    int nr = 0, i;
    for(i = 0; i <= 9; i++){
        nr += ff[i] % 2;
    }
    if(nr > n - p){
        return 0;
    }
    return 1;
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        for(i = 1; i <= n; i++){
            s[i] -= '0';
        }
        if(n % 2 == 1){
            for(i = 1; i < n; i++){
                cout<< 9;
            }
            cout<<"\n";
            continue;
        }
        ok = 1;
        for(i = 2; i < n; i++){
            if(s[i] != 0){
                ok = 0;
                break;
            }
        }
        if(ok == 1 && s[1] == 1 && s[n] < 2){
            for(i = 1; i <= n - 2; i++){
                cout<< 9;
            }
            cout<<"\n";
            continue;
        }
        for(i = 0; i <= 9; i++){
            ff[i] = 0;
        }
        nxt[n + 1] = n + 20;
        for(i = n; i >= 1; i--){
            if(s[i] != 0){
                nxt[i] = i;
            }
            else{
                nxt[i] = nxt[i + 1];
            }
        }
        for(i = 1; i <= n; i++){
            ff[ s[i] ]++;
            if(verif(i) && i < n){
                continue;
            }
            ff[ s[i] ]--;
            for(j = s[i] - 1; j >= 0; j--){
                ff[j]++;
                if(verif2(i)){
                    s[i] = j;
                    break;
                }
                else{
                    ff[j]--;
                }
            }
            break;
        }
        for(j = 1; j <= i; j++){
            cout<< (int) s[j];
        }
        nr = 0;
        for(j = 0; j <= 9; j++){
            nr += ff[j] % 2;
        }
        for(j = i + 1; j <= n - nr; j++){
            cout<< 9;
        }
        for(j = 9; j >= 0; j--){
            if(ff[j] % 2 == 1){
                cout<< j;
            }
        }
        cout<<"\n";
    }
}