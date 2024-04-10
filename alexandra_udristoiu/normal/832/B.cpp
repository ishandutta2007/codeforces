#include<iostream>
#include<cstring>
using namespace std;
int n, m, t, i, ok, poz, ii, x;
char s[100005], a[100005], ff[130], c[30], sol[100005];
int main(){
    cin>> c + 1;
    for(i = 1; i <= strlen(c + 1); i++){
        ff[ c[i] ] = 1;
    }
    cin>> a + 1;
    n = strlen(a + 1);
    poz = n + 1;
    for(i = 1; i <= n; i++){
        if(a[i] == '*'){
            poz = i;
            break;
        }
    }
    cin>> t;
    for(int t2 = 1; t2 <= t; t2++){
        cin>> s + 1;
        m = strlen(s + 1);
        ok = 1;
        if(m < n - 1){
            ok = 0;
        }
        for(i = 1; i < poz; i++){
            if( (a[i] == '?' && ff[ s[i] ] == 0) || (a[i] != '?' && a[i] != s[i]) ){
                ok = 0;
                break;
            }
        }
        x = n - poz;
        for(i = 1; i <= x; i++){
            if((a[n - i + 1] == '?' && ff[ s[m - i + 1] ] == 0) || (a[n - i + 1] != '?' && a[n - i + 1] != s[m - i + 1])){
                ok = 0;
                break;
            }
        }
        if(poz == n + 1 && n != m){
            ok = 0;
        }
        else{
            for(i = poz; i < m - x + 1; i++){
                if(ff[ s[i] ] == 1){
                    ok = 0;
                    break;
                }
            }
        }
        sol[t2] = ok;

    }
    for(i = 1; i <= t; i++){
        if(sol[i] == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}