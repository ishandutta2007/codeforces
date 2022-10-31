#include<iostream>
#define DIM 200005
using namespace std;
int n, k, q, i, x, y, m;
int v[DIM], s[DIM], sol[DIM];
int main(){
    cin>> n >> k >> q;
    m = DIM - 5;
    for(i = 1; i <= n; i++){
        cin>> x >> y;
        v[x]++;
        v[y + 1]--;
    }
    for(i = 1; i <= m; i++){
        v[i] += v[i - 1];
        if(v[i] >= k){
            s[i] = s[i - 1] + 1;
        }
        else{
            s[i] = s[i - 1];
        }
    }
    for(i = 1; i <= q; i++){
        cin>> x >> y;
        sol[i] = s[y] - s[x - 1];
    }
    for(i = 1; i <= q; i++){
        cout<< sol[i] <<"\n";
    }
    return 0;
}