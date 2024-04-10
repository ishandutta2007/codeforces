#include<iostream>
#define DIM 1000005
#define f first
#define s second
using namespace std;
int n, k, i, st, dr, x, lst;
long long sol;
pair<int, int> v[DIM];
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> x;
        if(v[x].f == 0){
            v[x] = make_pair(i, i);
        }
        else{
            v[x].s = i;
        }
    }
    for(i = 1; i <= k; i++){
        if(v[i].f != 0){
            if(v[i].f < lst){
                st = i - 1;
                break;
            }
            else{
                lst = v[i].s;
            }
        }
    }
    if(i == k + 1){
        cout<< k * 1LL * (k + 1) / 2;
        return 0;
    }
    v[k + 1] = make_pair(n + 1, n + 1);
    for(i = k; i >= 1; i--){
        if(v[i].f == 0){
            v[i] = v[i + 1];
        }
        else{
            if(v[i].s > v[i + 1].f){
                dr = i + 1;
                break;
            }
        }
    }
    for(i = 0; i <= st; i++){
        while(v[dr].f < v[i].s){
            dr++;
        }
        sol += k - dr + 2;
    }
    cout<< sol;
}