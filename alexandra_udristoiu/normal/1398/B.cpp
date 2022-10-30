#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t, n, i, nr, m, sol;
char s[105];
int v[105];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        m = nr = 0;
        sol = 0;
        for(i = 1; i <= n; i++){
            if(s[i] == '1'){
                nr++;
            }
            else{
                v[++m] = -nr;
                nr = 0;
            }
        }
        v[++m] = -nr;
        sort(v + 1, v + m + 1);
        for(i = 1; i <= m; i += 2){
            sol -= v[i];
        }
        cout<< sol <<"\n";
    }
}