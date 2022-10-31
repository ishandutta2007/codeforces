#include<iostream>
#include<algorithm>
#define DIM 500005
#define mod 1000000007
using namespace std;
int n, i, st, dr, mid, sol;
int v[DIM], w[DIM], aib[DIM];
void update(int x, int val){
    for(; x <= n; x += (x & -x) ){
        aib[x] += val;
        if(aib[x] >= mod){
            aib[x] -= mod;
        }
    }
}
int query(int x){
    int sol = 0;
    for(; x >= 1; x -= (x & -x) ){
        sol += aib[x];
        if(sol >= mod){
            sol -= mod;
        }
    }
    return sol;
}
void solve(){
    int i, x;
    for(i = 1; i <= n; i++){
        aib[i] = 0;
    }
    for(i = 1; i <= n; i++){
        x = query(v[i]);
        update(v[i], i);
        sol = (sol + x * 1LL * w[ v[i] ] % mod * (n - i + 1) ) % mod;
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        w[i] = v[i];
    }
    sort(w + 1, w + n + 1);
    for(i = 1; i <= n; i++){
        st = 1;
        dr = n;
        while(st <= dr){
            mid = (st + dr) / 2;
            if(w[mid] == v[i]){
                break;
            }
            else{
                if(w[mid] < v[i]){
                    st = mid + 1;
                }
                else{
                    dr = mid - 1;
                }
            }
        }
        v[i] = mid;
    }
    solve();
    for(i = 1; i <= n / 2; i++){
        swap(v[i], v[n - i + 1]);
    }
    for(i = 1; i <= n; i++){
        sol = (sol + w[ v[i] ] * 1LL * i % mod * (n - i + 1) ) % mod;
    }
    solve();
    cout<< sol;
}