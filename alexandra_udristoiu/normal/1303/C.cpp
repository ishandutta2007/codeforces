#include<iostream>
#include<cstring>
using namespace std;
int n, t, i, ok, p, u, k;
char sol[200], viz[200], s[205], v[200][2], x;
void vecin(char x, char y){
    if(v[x][0] == y || v[x][1] == y){
        return;
    }
    if(v[x][1] != 0){
        ok = 0;
    }
    else{
        if(v[x][0] == 0){
            v[x][0] = y;
        }
        else{
            v[x][1] = y;
        }
    }
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        ok = 1;
        k = 0;
        for(i = 'a'; i <= 'z'; i++){
            v[i][0] = v[i][1] = 0;
            viz[i] = 0;
        }
        for(i = 1; i < n; i++){
            vecin(s[i], s[i + 1]);
            vecin(s[i + 1], s[i]);
        }
        for(i = 'a'; i <= 'z'; i++){
            if(v[i][1] == 0 && viz[i] == 0){
                x = i;
                while(x != 0){
                    sol[++k] = x;
                    viz[x] = 1;
                    if(viz[ v[x][0] ] == 1 && viz[ v[x][1] ] == 1){
                        ok = 0;
                        break;
                    }
                    if(viz[ v[x][0] ] == 0){
                        x = v[x][0];
                    }
                    else{
                        x = v[x][1];
                    }
                }
            }
        }
        for(i = 'a'; i <= 'z'; i++){
            if(viz[i] == 0){
                ok = 0;
                break;
            }
        }
        if(ok == 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n"<< sol + 1 <<"\n";
        }
    }
}