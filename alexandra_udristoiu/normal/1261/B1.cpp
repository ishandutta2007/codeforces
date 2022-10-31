#include<iostream>
#include<algorithm>
#define DIM 200005
#define f first
#define s second
using namespace std;
int n, q, i, u;
int v[DIM], sol[DIM], aib[DIM];
pair<int, int> p[DIM];
struct str{
    int k, pos, ind;
};
str w[DIM];
int cmp(str a, str b){
    return a.k < b.k;
}
void update(int x){
    for(; x <= n; x += (x & -x) ){
        aib[x]++;
    }
}
int query(int x){
    x--;
    int ii, p = 0;
    for(ii = 18; ii >= 0; ii--){
        if(p + (1 << ii) <= n && aib[ p + (1 << ii) ] <= x){
            p += (1 << ii);
            x -= aib[p];
        }
    }
    return p + 1;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        p[i] = make_pair(-v[i], i);
    }
    sort(p + 1, p + n + 1);
    cin>> q;
    for(i = 1; i <= q; i++){
        cin>> w[i].k >> w[i].pos;
        w[i].ind = i;
    }
    sort(w + 1, w + q + 1, cmp);
    u = 1;
    for(i = 1; i <= n; i++){
        update(p[i].s);
        while(w[u].k == i){
            sol[ w[u].ind ] = v[ query(w[u].pos) ];
            u++;
        }
    }
    for(i = 1; i <= q; i++){
        cout<< sol[i] <<"\n";
    }
}