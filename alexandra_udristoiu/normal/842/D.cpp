#include<iostream>
#include<algorithm>
using namespace std;
int n, i, q, m, st, dr, mid, sol, x, p, u, j, y;
int v[300005], sol2[300005];
int main(){
    cin>> m >> q;
    for(i = 1; i <= m; i++){
        cin>> v[i];
    }
    sort(v + 1, v + m + 1);
    n = 1;
    for(i = 2; i <= m; i++){
        if(v[i] != v[n]){
            v[++n] = v[i];
        }
    }
    for(j = 1; j <= q; j++){
        cin>> y;
        x ^= y;
        p = 1;
        u = n;
        sol = 0;
        for(i = 19; i >= 0; i--){
            sol *= 2;
            st = p;
            dr = u;
            while(st <= dr){
                mid = (st + dr) / 2;
                if( ( (v[mid] >> i) & 1) == 0){
                    st = mid + 1;
                }
                else{
                    dr = mid - 1;
                }
            }
            if(p > u){
                continue;
            }
            if( ( (x >> i) & 1) == 0){
                if(dr - p + 1 < (1 << i)){
                    u = dr;
                }
                else{
                    p = dr + 1;
                    sol++;
                }
            }
            else{
                if(u - dr < (1 << i)){
                    p = dr + 1;
                }
                else{
                    u = dr;
                    sol++;
                }
            }
        }
        sol2[j] = sol;
    }
    for(i = 1; i <= q; i++){
        cout<< sol2[i] <<"\n";
    }
    return 0;
}