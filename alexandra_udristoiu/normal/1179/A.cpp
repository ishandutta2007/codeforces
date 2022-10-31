#include<iostream>
#include<cstdio>
#include<algorithm>
#define DIM 300005
#define f first
#define s second
using namespace std;
int n, q, i, p, u, ii, j;
int v[DIM];
pair<int, int> sol[DIM];
pair<long long, int> w[DIM];
int main(){
    cin>> n >> q;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= q; i++){
        cin>> w[i].f;
        w[i].s = i;
    }
    sort(w + 1, w + q + 1);
    ii = 1;
    for(i = 2; i <= n; i++){
        if(v[i] > v[ii]){
            ii = i;
        }
    }
    j = 1;
    p = 1;
    u = n;
    for(i = 1; i < ii; i++){
        while(w[j].f == i){
            sol[ w[j].s ] = make_pair(v[p], v[p + 1]);
            j++;
        }
        v[++u] = min(v[p], v[p + 1]);
        v[p + 1] = max(v[p], v[p + 1]);
        p++;
    }
    for(; j <= q; j++){
        w[j].f = (w[j].f - ii) % (n - 1);
        sol[ w[j].s ] = make_pair(v[p], v[p + w[j].f + 1]);
    }
    for(i = 1; i <= q; i++){
        printf("%d %d\n", sol[i].f, sol[i].s);
    }
}