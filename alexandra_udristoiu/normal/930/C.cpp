#include<iostream>
#define DIM 100005
using namespace std;
int n, k, i, st, dr, mid, nr, x, y, sol;
int d[2][DIM], v[DIM], lst[2][DIM], w[DIM];
int main(){
    cin>> k >> n;
    for(i = 1; i <= k; i++){
        cin>> x >> y;
        v[x]++;
        v[y + 1]--;
    }
    for(i = 2; i <= n; i++){
        v[i] += v[i - 1];
    }
    for(i = 1; i <= n; i++){
        if(w[nr] <= v[i]){
            w[++nr] = v[i];
        }
        else{
            st = 1;
            dr = nr;
            while(st <= dr){
                mid = (st + dr) / 2;
                if(w[mid] <= v[i]){
                    st = mid + 1;
                }
                else{
                    dr = mid - 1;
                }
            }
            w[dr + 1] = v[i];
        }
        d[0][i] = nr;
        lst[0][i] = w[nr];
    }
    nr = 0;
    for(i = n; i >= 1; i--){
        if(w[nr] <= v[i]){
            w[++nr] = v[i];
        }
        else{
            st = 1;
            dr = nr;
            while(st <= dr){
                mid = (st + dr) / 2;
                if(w[mid] <= v[i]){
                    st = mid + 1;
                }
                else{
                    dr = mid - 1;
                }
            }
            w[dr + 1] = v[i];
        }
        d[1][i] = nr;
        lst[1][i] = w[nr];
    }
    lst[0][0] = lst[1][n + 1] = -1;
    for(i = 1; i <= n; i++){
        if(v[i] >= lst[0][i - 1] && v[i] >= lst[1][i + 1]){
            sol = max(sol, d[0][i - 1] + d[1][i + 1] + 1);
        }
        else{
            sol = max(sol, d[0][i - 1] + d[1][i + 1]);
        }
    }
    cout<< sol;
}