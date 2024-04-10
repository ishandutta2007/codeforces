#include<iostream>
using namespace std;
int n, m, i, st, dr, mid;
int v[300005];
int verif(int k){
    int i, x = 0;
    for(i = 1; i <= n; i++){
        if(v[i] <= x){
            if(v[i] + k < x){
                return 0;
            }
        }
        else{
            if(v[i] + k < m || (v[i] + k) % m < x){
                x = v[i];
            }
        }
    }
    return 1;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    st = 0;
    dr = m - 1;
    while(st <= dr){
        mid = (st + dr) / 2;
        if( verif(mid) ){
            dr = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    cout<< st;
}