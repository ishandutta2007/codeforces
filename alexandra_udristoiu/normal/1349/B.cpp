#include<iostream>
#define DIM 100005
using namespace std;
int n, k, i, x, nr, ok, t, p, minim;
int sum[DIM], num[DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        ok = nr = 0;
        p = 0;
        minim = n + 1;
        for(i = 1; i <= n; i++){
            cin>> x;
            sum[i] = sum[i - 1] + (x == k);
            num[i] = num[i - 1];
            if(x >= k){
                num[i]++;
            }
            if(x < k){
                num[i]--;
            }
            for(; p < i - 1; p++){
                minim = min(minim, num[p]);
            }
            if(num[i] - minim > 0){
                ok = 1;
            }
        }
        if(n == 1 && sum[1] == 1){
            ok = 1;
        }
        if(sum[n] == 0){
            ok = 0;
        }
        if(ok == 1){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
}