#include<iostream>
#include<algorithm>
#define f first
#define s second
#define DIM 100005
using namespace std;
int n, i, j, nod;
int t[2 * DIM];
pair<int, int> v[DIM];
int cmp(pair<int, int> a, pair<int, int> b){
    return a.f > b.f;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].f;
        v[i].s = i;
    }
    sort(v + 1, v + n + 1, cmp);
    v[0].f = n;
    for(i = 2; i <= n; i++){
        t[ 2 * v[i].s - 1] = 2 * v[i - 1].s - 1;
    }
    for(i = 1; i <= n; i++){
        if(i + v[i].f - 1 <= n){
            t[ 2 * v[i].s ] = 2 * v[ i + v[i].f - 1 ].s - 1;
        }
        else{
            nod = 2 * v[i - 1].s;
            for(j = 1; j <= v[i - 1].f - v[i].f; j++){
                nod = t[nod];
            }
            t[ 2 * v[i].s ] = nod;
        }
    }
    for(i = 1; i <= n + n; i++){
        if(t[i] != 0){
            cout<< t[i] <<" "<< i <<"\n";
        }
    }
}