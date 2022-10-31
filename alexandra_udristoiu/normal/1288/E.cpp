#include<iostream>
#include<cstring>
#define DIM 300005
#define f first
#define s second
using namespace std;
int n, m, i;
int v[DIM], aib[DIM], viz[DIM], lst[DIM];
pair<int, int> p[DIM];
void update(int x, int val){
    for(; x <= max(n, m); x += (x & -x) ){
        aib[x] += val;
    }
}
int query(int x){
    int sum = 0;
    for(; x >= 1; x -= (x & -x) ){
        sum += aib[x];
    }
    return sum;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        p[i] = make_pair(i, i);
    }
    for(i = m; i >= 1; i--){
        cin>> v[i];
        p[ v[i] ].f = 1;
        viz[ v[i] ] = 1;
    }
    for(i = n; i >= 1; i--){
        if(viz[i] == 0){
            p[i].s = i + viz[i + 1];
        }
        viz[i] += viz[i + 1];
    }
    memset(viz, 0, sizeof(viz) );
    for(i = m; i >= 1; i--){
        if(viz[ v[i] ] == 0){
            viz[ v[i] ] = 1;
            p[ v[i] ].s = v[i] + query(n - v[i] + 1);
            update(n - v[i] + 1, 1);
        }
    }
    memset(aib, 0, sizeof(aib) );
    for(i = 1; i <= m; i++){
        p[ v[i] ].s = max(p[ v[i] ].s, 1 + query(m) - query(lst[ v[i] ]) );
        if(lst[ v[i] ] != 0){
            update(lst[ v[i] ], -1);
        }
        lst[ v[i] ] = i;
        update(i, 1);
    }
    for(i = 1; i <= n; i++){
        cout<< p[i].f <<" "<< p[i].s <<"\n";
    }
}