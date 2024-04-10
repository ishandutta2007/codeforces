#include<iostream>
#include<algorithm>
#define DIM 500005
using namespace std;
int n, k, dif, i, u;
int v[DIM], aib[DIM], d[DIM];
void update(int x){
    for(; x <= n; x += (x & -x) ){
        aib[x]++;
    }
}
int query(int x){
    int sum = 0;
    for(; x >= 1; x -= (x & -x)){
        sum += aib[x];
    }
    if(x >= 0){
        sum++;
    }
    return sum;
}
int main(){
    cin>> n >> k >> dif;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    u = 1;
    for(i = 1; i <= n; i++){
        while(v[i] - v[u] > dif){
            u++;
        }
        if(i - u + 1 >= k){
            if(query(i - k) - query(u - 2) > 0){
                d[i] = 1;
                update(i);
            }
        }
    }
    if(d[n] == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}