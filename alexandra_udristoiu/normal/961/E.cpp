#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, j;
int a[DIM], b[DIM], aib[DIM];
long long sol;
vector<int> v[DIM];
void update(int x, int val){
    for(; x <= n; x += (x & -x)){
        aib[x] += val;
    }
}
int query(int x){
    int sum = 0;
    for(; x >= 1; x -= (x & -x)){
        sum += aib[x];
    }
    return sum;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> a[i];
        a[i] = min(a[i], n);
        update(i, 1);
        v[ a[i] ].push_back(i);
    }
    for(i = 1; i <= n; i++){
        sol += query(a[i]);
        if(a[i] >= i){
            sol--;
        }
        for(j = 0; j < v[i].size(); j++){
            update(v[i][j], -1);
        }
    }
    cout<< sol / 2;
}