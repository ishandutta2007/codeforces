#include<iostream>
#include<cstring>
using namespace std;
int t, n, i, p, u, nr;
char s[105];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        p = u = nr = 0;
        for(i = 1; i <= n; i++){
            if(s[i] == '1'){
                if(p == 0){
                    p = i;
                }
                u = i;
            }
        }
        for(i = p; i <= u; i++){
            if(s[i] == '0'){
                nr++;
            }
        }
        cout<< nr <<"\n";
    }
}