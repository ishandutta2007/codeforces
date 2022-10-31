#include<iostream>
#define DIM 200005
using namespace std;
int n, m, i, x, k, y, u, nr, ok, maxim;
int v[DIM], w[DIM];
long long cost;
int main(){
    cin>> n >> m;
    cin>> x >> k >> y;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= m; i++){
        cin>> w[i];
    }
    u = 1;
    ok = 1;
    for(i = 1; i <= n + 1; i++){
        if(v[i] != w[u]){
            nr++;
            maxim = max(maxim, v[i]);
            continue;
        }
        if(nr < k && maxim > max(w[u], w[u - 1]) ){
            ok = 0;
            break;
        }
        if(maxim < max(w[u], w[u - 1]) ){
            cost += min(nr * 1LL * y, (nr % k) * 1LL * y + (nr / k) * 1LL * x );
        }
        else if(nr >= k){
            cost += min( (nr % k) * 1LL * y + (nr / k) * 1LL * x, x + (nr - k) * 1LL * y );
        }
        u++;
        nr = maxim = 0;
    }
    if(ok == 1 && u > m){
        cout<< cost;
    }
    else{
        cout<< -1;
    }
}