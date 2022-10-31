#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, i, j, m, x;
long long sol;
int num[1000005], ok[DIM];
vector<int> v[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> m;
        for(j = 0; j < m; j++){
            cin>> x;
            v[i].push_back(x);
        }
        ok[i] = 1;
        for(j = 1; j < m; j++){
            if(v[i][j] > v[i][j - 1]){
                ok[i] = 0;
                break;
            }
        }
        if(ok[i] == 1){
            num[ v[i][0] ]++;
        }
    }
    for(i = 1; i <= 1000000; i++){
        num[i] += num[i - 1];
    }
    sol = n * 1LL * n;
    for(i = 1; i <= n; i++){
        if(ok[i] == 1){
            sol -= num[ v[i][ v[i].size() - 1] ];
        }
    }
    cout<< sol;
}