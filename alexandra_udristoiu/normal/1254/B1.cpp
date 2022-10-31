#include<iostream>
#define DIM 100005
using namespace std;
int n, i, sum, ii, x, k;
int a[DIM], p[DIM], u[DIM];
long long sol, minim, st, dr, sol2;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> a[i];
        sum += a[i];
    }
    if(sum == 1){
        cout<< -1;
        return 0;
    }
    sol2 = 1000000000000LL;
    for(k = 2; k <= sum; k++){
        if(sum % k != 0){
            continue;
        }
        sol = 0;
        for(i = 1; i <= sum / k; i++){
            p[i] = u[i] = 1 + u[i - 1];
            x = 0;
            while(u[i] <= n){
                x += a[ u[i] ];
                if(x == k){
                    break;
                }
                u[i]++;
            }
        }
        for(ii = 1; ii <= sum / k; ii++){
            minim = 1000000000000LL;
            st = dr = 0;
            x = 0;
            for(i = p[ii]; i <= u[ii]; i++){
                dr += i * a[i];
            }
            for(i = p[ii]; i <= u[ii]; i++){
                minim = min(minim, dr - (k - x) * 1LL * i + x * 1LL * i - st);
                if(a[i] == 1){
                    x++;
                    st += i;
                    dr -= i;
                }
            }
            sol += minim;
        }
        sol2 = min(sol, sol2);
    }
    cout<< sol2;
}