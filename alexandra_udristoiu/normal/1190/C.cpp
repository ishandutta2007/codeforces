#include<iostream>
#define DIM 100005
using namespace std;
int n, k, i, t, st0, dr0, st1, dr1, ok;
char s[DIM];
int p[DIM][2], u[DIM][2];
int main(){
    cin>> n >> k;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        s[i] -= '0';
        u[i][0] = u[i - 1][0];
        u[i][1] = u[i - 1][1];
        u[i][ s[i] ] = i;
    }
    for(i = n; i >= 1; i--){
        p[i][0] = p[i + 1][0];
        p[i][1] = p[i + 1][1];
        p[i][ s[i] ] = i;
    }
    if(u[n][0] - p[1][0] + 1 <= k || u[n][1] - p[1][1] + 1 <= k){
        cout<<"tokitsukaze";
        return 0;
    }
    ok = 1;
    for(i = 1; i <= n - k + 1; i++){
        for(t = 0; t < 2; t++){
            st0 = min(i, p[1][t]);
            dr0 = max(i + k - 1, u[n][t]);
            if(u[n][1 - t] <= i + k - 1){
                dr1 = u[i - 1][1 - t];
            }
            else{
                dr1 = u[n][1 - t];
            }
            if(p[1][1 - t] >= i){
                st1 = p[i + k][1 - t];
            }
            else{
                st1 = p[1][1 - t];
            }
            if(dr1 - st1 + 1 > k && dr0 - st0 + 1 > k){
                ok = 0;
            }
        }
    }
    if(ok == 1){
        cout<<"quailty";
    }
    else{
        cout<<"once again";
    }
}