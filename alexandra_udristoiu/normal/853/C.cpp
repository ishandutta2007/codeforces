#include<iostream>
#include<algorithm>
#define DIM 200005
using namespace std;
int n, q, i, ii1, ii2, jj1, jj2;
long long sol[DIM];
int v[4][DIM], aib[DIM];
struct str{
    int ii, jj, ind;
};
str w[4][DIM];
int cmp(str a, str b){
    return a.ii < b.ii;
}
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
void solve(int t){
    int i, u = 1;
    for(i = 1; i <= n; i++){
        aib[i] = 0;
    }
    while(u <= q && w[t][u].ii == 0){
        u++;
    }
    for(i = 1; i <= n; i++){
        update(v[t][i]);
        while(u <= q && w[t][u].ii == i){
            if(w[t][u].jj != 0){
                int x = query(w[t][u].jj);
                sol[ w[t][u].ind ] -= x * 1LL * (x - 1) / 2;
            }
            u++;
        }
    }
}
int main(){
    cin>> n >> q;
    for(i = 1; i <= n; i++){
        cin>> v[0][i];
        v[1][i] = n - v[0][i] + 1;
        v[2][n - i + 1] = v[0][i];
        v[3][n - i + 1] = v[1][i];
    }
    for(i = 1; i <= q; i++){
        cin>> ii1 >> jj1 >> ii2 >> jj2;
        sol[i] = (ii1 - 1) * 1LL * (ii1 - 2) / 2 + (jj1 - 1) * 1LL * (jj1 - 2) / 2 +
                 (n - ii2) * 1LL * (n - ii2 - 1) / 2 + (n - jj2) * 1LL * (n - jj2 - 1) / 2;
        w[0][i].ind = w[1][i].ind = w[2][i].ind = w[3][i].ind = i;
        w[0][i].ii = w[1][i].ii = ii1 - 1;
        w[0][i].jj = w[2][i].jj = jj1 - 1;
        w[2][i].ii = w[3][i].ii = n - ii2;
        w[1][i].jj = w[3][i].jj = n - jj2;
    }
    for(i = 0; i < 4; i++){
        sort(w[i] + 1, w[i] + q + 1, cmp);
    }
    for(i = 0; i < 4; i++){
        solve(i);
    }
    for(i = 1; i <= q; i++){
        cout<< n * 1LL * (n - 1) / 2 - sol[i] <<"\n";
    }
    return 0;
}