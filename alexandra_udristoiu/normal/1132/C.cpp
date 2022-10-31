#include<iostream>
#define f first
#define s second
using namespace std;
int n, q, i, j, sol, sum;
int v[5005], s[5005];
pair<int, int> p[5005];
int main(){
    cin>> n >> q;
    for(i = 1; i <= q; i++){
        cin>> p[i].f >> p[i].s;
        v[ p[i].f ]++;
        v[ p[i].s + 1 ]--;
    }
    for(i = 1; i <= n; i++){
        v[i] += v[i - 1];
    }
    for(i = 1; i <= q; i++){
        for(j = p[i].f; j <= p[i].s; j++){
            v[j]--;
        }
        sum = 0;
        for(j = 1; j <= n; j++){
            if(v[j] != 0){
                sum++;
            }
            s[j] = s[j - 1];
            if(v[j] == 1){
                s[j]++;
            }
        }
        for(j = 1; j <= q; j++){
            if(j != i){
                sol = max(sol, sum - s[ p[j].s ] + s[ p[j].f - 1 ]);
            }
        }
        for(j = p[i].f; j <= p[i].s; j++){
            v[j]++;
        }
    }
    cout<< sol;
}