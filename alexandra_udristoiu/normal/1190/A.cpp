#include<iostream>
using namespace std;
int m, i, sol, u, u2;
long long n, k, nr, v[100005], x;
int main(){
    cin>> n >> m >> k;
    for(i = 1; i <= m; i++){
        cin>> v[i];
        v[i]--;
    }
    u = 1;
    while(u <= m){
        x = (v[u] - u + 1) / k;
        u2 = u;
        do{
            u = u2;
            sol++;
            while(u2 <= m && x == (v[u2] - nr) / k ){
                u2++;
            }
            nr += u2 - u;
        }while(u2 != u);
        sol--;
    }
    cout<< sol;
}