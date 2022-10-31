#include<iostream>
#include<algorithm>
using namespace std;
int n, i, t;
int u[2], v[2][100005], w[100005];
long long sum[2];
int main(){
    cin>> n;
    for(t = 0; t < 2; t++){
        for(i = 1; i <= n; i++){
            cin>> w[i];
        }
        sort(w + 1, w + n + 1);
        for(i = 1; i <= n; i++){
            v[t][i] = w[i];
        }
    }
    u[0] = u[1] = n;
    t = 0;
    for(i = 1; i <= n + n; i++){
        if(v[t][ u[t] ] > v[1 - t][ u[1 - t] ]){
            sum[t] += v[t][ u[t] ];
            u[t]--;
        }
        else{
            u[1 - t]--;
        }
        t = 1 - t;
    }
    cout<< sum[0] - sum[1];
}