#include<iostream>
#include<algorithm>
#define DIM 100005
using namespace std;
int n, i, q, st, dr, mid;
long long p, u, m;
long long v[DIM], w[DIM], sum[DIM], sol[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i < n; i++){
        w[i] = v[i + 1] - v[i];
    }
    sort(w + 1, w + n);
    for(i = 1; i < n; i++){
        sum[i] = sum[i - 1] + w[i];
    }
    cin>> q;
    for(i = 1; i <= q; i++){
        cin>> p >> u;
        m = u - p + 1;
        st = 1;
        dr = n - 1;
        while(st <= dr){
            mid = (st + dr) / 2;
            if(w[mid] > m){
               dr = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        sol[i] = m + sum[dr] + (n - 1 - dr) * 1LL * m;
    }
    for(i = 1; i <= q; i++){
        cout<< sol[i] <<" ";
    }
}