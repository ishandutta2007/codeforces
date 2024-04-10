#include<iostream>
#define DIM 100005
using namespace std;
int n, i, x, nr;
int aib[DIM], v[DIM], p[DIM];
void update(int x){
    for(; x <= n; x += (x & -x) ){
        aib[x]++;
    }
}
int query(int x){
    int sum = 0;
    for(; x >= 1; x -= (x & -x) ){
        sum += aib[x];
    }
    return sum;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        p[x] = i;
    }
    for(i = 1; i <= n; i++){
        cin>> v[i];
        v[i] = p[ v[i] ];
    }
    for(i = 1; i <= n; i++){
        update(v[i]);
        if(query(v[i]) != v[i]){
            nr++;
        }
    }
    cout<< nr;
}