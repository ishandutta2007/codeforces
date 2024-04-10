#include<iostream>
#define DIM 100005
using namespace std;
int n, i, u, st, dr, mid, lst;
int c[3 * DIM], v[3 * DIM], sol[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = n + 1; i <= 3 * n; i++){
        v[i] = v[i - n];
    }
    c[1] = u = lst = 1;
    for(i = 2; i <= 3 * n; i++){
        st = 1;
        dr = u;
        while(st <= dr){
            mid = (st + dr) / 2;
            if(v[i] < v[ c[mid] ] / 2.0){
                st = mid + 1;
            }
            else{
                dr = mid - 1;
            }
        }
        for(; lst <= min(c[dr], n); lst++){
            sol[lst] = i - lst;
        }
        while(u > 0 && v[ c[u] ] < v[i]){
            u--;
        }
        c[++u] = i;
    }
    for(; lst <= n; lst++){
        sol[lst] = -1;
    }
    for(i = 1; i <= n; i++){
        cout<< sol[i] <<" ";
    }
}