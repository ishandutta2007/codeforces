#include<iostream>
#include<cstring>
using namespace std;
int n, i, ok, j, ii, m;
char s[5005], c[5005];
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    for(i = 2; i <= n / 2; i++){
        if(s[i] != s[1]){
            ok = 1;
        }
    }
    if(ok == 0){
        cout<<"Impossible";
        return 0;
    }
    for(ii = 1; ii <= n / 2; ii++){
        m = 0;
        for(i = ii + 1; i <= n; i++){
            c[++m] = s[i];
        }
        for(i = 1; i <= ii; i++){
            c[++m] = s[i];
        }
        ok = 1;
        for(i = 1; i <= n / 2; i++){
            if(c[i] != c[n - i + 1]){
                ok = 0;
            }
        }
        if(ok == 1){
            for(i = 1; i <= n / 2; i++){
                if(c[i] != s[i]){
                    ok = 0;
                }
            }
            if(ok == 0){
                cout<< 1;
                return 0;
            }
        }
    }
    cout<< 2;
}