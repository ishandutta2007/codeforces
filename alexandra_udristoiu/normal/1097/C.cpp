#include<iostream>
#include<cstring>
using namespace std;
int n, i, nr, ok, j, m, sol;
char s[500005];
int st[500005], dr[500005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> s + 1;
        m = strlen(s + 1);
        nr = 0;
        ok = 1;
        for(j = 1; j <= m; j++){
            if(s[j] == '('){
                nr++;
            }
            else{
                nr--;
            }
            if(nr < 0){
                ok = 0;
            }
        }
        if(ok == 1){
            st[nr]++;
        }

        nr = 0;
        ok = 1;
        for(j = m; j >= 1; j--){
            if(s[j] == '('){
                nr--;
            }
            else{
                nr++;
            }
            if(nr < 0){
                ok = 0;
            }
        }
        if(ok == 1){
            dr[nr]++;
        }
    }
    sol += st[0] / 2;
    for(i = 1; i <= 500000; i++){
        sol += min(st[i], dr[i]);
    }
    cout<< sol;
}