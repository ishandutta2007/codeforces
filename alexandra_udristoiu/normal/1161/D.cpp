#include<iostream>
#include<cstring>
#define mod 998244353
using namespace std;
int n, i, ii, sol, sum, ok;
char s[1005];
int a[1005], viz[1005];
void dfs2(int i){
    if(viz[i] == 1){
        return;
    }
    viz[i] = 1;
    dfs2(n - i + 1);
    if(s[i] != '?' && s[ii - i + 1] != '?'){
        dfs2(ii - i + 1);
    }
}
void dfs1(int i, int x){
    if(viz[i] == 1){
        if(a[i] != x){
            ok = 0;
        }
        return;
    }
    viz[i] = 1;
    a[i] = x;
    dfs1(n - i + 1, x);
    if(i <= ii && s[i] != '?' && s[ii - i + 1] != '?'){
        dfs1(ii - i + 1, x ^ (s[i] - '0') ^ (s[ii - i + 1] - '0') );
    }
}
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    for(i = 1; i <= n / 2; i++){
        swap(s[i], s[n - i + 1]);
    }
    for(ii = 1; ii < n; ii++){
        ok = 1;
        for(i = 1; i <= n; i++){
            viz[i] = 0;
        }
        for(i = n; i > ii; i--){
            if(s[i] != '?'){
                dfs1(i, s[i] - '0');
            }
        }
        if(s[i] != '?'){
            dfs1(i, (s[i] - '0') ^ 1);
        }
        if(ok == 0){
            continue;
        }
        sum = 1;
        for(i = ii; i >= 1; i--){
            if(viz[i] == 0){
                sum = sum * 2 % mod;
                dfs2(i);
            }
        }
        for(i = ii + 1; i <= n / 2 + n % 2; i++){
            if(viz[i] == 0){
                sum = sum * 2 % mod;
            }
        }
        for(i = 2; i <= ii / 2 + ii % 2; i++){
            if(s[i] == '?' && s[ii - i + 1] == '?'){
                sum = sum * 2 % mod;
            }
        }
        sol = (sol + sum) % mod;
    }
    cout<< sol;
}