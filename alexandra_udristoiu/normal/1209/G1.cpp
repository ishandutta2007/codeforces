#include<iostream>
#define DIM 200005
using namespace std;
int n, i, j, u, nr, sum, q;
int v[DIM], frst[DIM], lst[DIM], num[DIM];
int main(){
    cin>> n >> q;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        num[ v[i] ]++;
        lst[ v[i] ] = i;
    }
    for(i = n; i >= 1; i--){
        frst[ v[i] ] = i;
    }
    for(i = 1; i <= n; i++){
        nr = 0;
        u = lst[ v[i] ];
        for(j = i; j <= u; j++){
            if(frst[ v[j] ] == j){
                u = max(u, lst[ v[j] ]);
                nr = max(nr, num[ v[j] ]);
            }
        }
        sum += u - i + 1 - nr;
        i = u;
    }
    cout<< sum;
}