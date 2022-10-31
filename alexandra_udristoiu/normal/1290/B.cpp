#include<iostream>
#include<cstring>
using namespace std;
int n, q, i, p, u, nr, j;
char s[200005];
int sum[200005][28];
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= 26; j++){
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][ s[i] - 'a' + 1]++;
    }
    cin>> q;
    for(; q; q--){
        cin>> p >> u;
        nr = 0;
        for(i = 1; i <= 26; i++){
            if(sum[u][i] - sum[p - 1][i] != 0){
                nr++;
            }
        }
        if(p == u){
            cout<<"Yes\n";
            continue;
        }
        if(nr > 2 || s[p] != s[u]){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}