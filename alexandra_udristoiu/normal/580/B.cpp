#include<iostream>
#include<algorithm>
#define f first
#define s second
using namespace std;
int n, d, i, p;
long long sum, sol;
pair<int, int> v[100005];
int main(){
    cin>> n >> d;
    for(i = 1; i <= n; i++){
        cin>> v[i].f >> v[i].s;
    }
    sort(v + 1, v + n + 1);
    p = 1;
    for(i = 1; i <= n; i++){
        while(p <= n && v[p].f < v[i].f + d){
            sum += v[p].s;
            p++;
        }
        sol = max(sol, sum);
        sum -= v[i].s;
    }
    cout<< sol;
}