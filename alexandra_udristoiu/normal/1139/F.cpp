#include<iostream>
#include<algorithm>
#define DIM 100005
using namespace std;
int n, m, i, nr, k;
int sol[DIM], aib[2][4 * DIM], w[4 * DIM], x[DIM], y[DIM], z[DIM];
struct str{
    int p, t, ind, x, y;
};
str v[3 * DIM];
int cmp(str a, str b){
    if(a.p == b.p){
        return a.t < b.t;
    }
    return a.p < b.p;
}
int cautbin(int x){
    int st = 1, dr = k, mid;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(w[mid] == x){
            return mid;
        }
        if(w[mid] < x){
            st = mid + 1;
        }
        else{
            dr = mid - 1;
        }
    }
}
void update(int t, int x, int val){
    for(; x <= k; x += (x & -x) ){
        aib[t][x] += val;
    }
}
int query(int t, int x){
    int sum = 0;
    for(; x >= 1; x -= (x & -x) ){
        sum += aib[t][x];
    }
    return sum;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> x[i];
    }
    for(i = 1; i <= n; i++){
        cin>> y[i];
    }
    for(i = 1; i <= n; i++){
        cin>> z[i];
    }
    for(i = 1; i <= n; i++){
        nr += 2;
        v[nr - 1].p = x[i];
        v[nr].p = y[i];
        v[nr - 1].t = 1;
        v[nr].t = 3;
        v[nr - 1].x = v[nr].x = x[i] + z[i];
        v[nr - 1].y = v[nr].y = x[i] - z[i];
        w[nr - 1] = v[nr].x;
        w[nr] = v[nr].y;
    }
    k = nr;
    for(i = 1; i <= m; i++){
        cin>> x[i];
    }
    for(i = 1; i <= m; i++){
        cin>> y[i];
    }
    for(i = 1; i <= m; i++){
        nr++;
        v[nr].p = x[i];
        v[nr].t = 2;
        v[nr].ind = i;
        v[nr].x = x[i] + y[i];
        v[nr].y = x[i] - y[i];
        w[++k] = x[i] + y[i];
        w[++k] = x[i] - y[i];
    }
    sort(w + 1, w + k + 1);
    k = 1;
    for(i = 2; i <= 2 * n + 2 * m; i++){
        if(w[k] != w[i]){
            w[++k] = w[i];
        }
    }
    for(i = 1; i <= nr; i++){
        v[i].x = cautbin(v[i].x);
        v[i].y = cautbin(v[i].y);
    }
    sort(v + 1, v + nr + 1, cmp);
    for(i = 1; i <= nr; i++){
        if(v[i].t == 1){
            update(0, v[i].x, 1);
            update(1, v[i].y, -1);
        }
        if(v[i].t == 2){
            sol[ v[i].ind ] = query(0, v[i].x) + query(1, k) - query(1, v[i].y);
        }
        if(v[i].t == 3){
            update(0, v[i].x, -1);
            update(1, v[i].y, 1);
        }
    }
    for(i = 1; i <= m; i++){
        cout<< sol[i] <<" ";
    }
}