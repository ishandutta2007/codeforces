#include<iostream>
#define DIM 100005
using namespace std;
int n, r, i, j, maxim;
int d[DIM];
struct str{
    int t, x, y;
};
str v[DIM];
int modul(int x){
    if(x > 0){
        return x;
    }
    return -x;
}
int dist(str a, str b){
    return modul(b.x - a.x) + modul(b.y - a.y);
}
int main(){
    cin>> r >> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].t >> v[i].x >> v[i].y;
    }
    maxim = -10000000;
    v[0] = {0, 1, 1};
    for(i = 1; i <= n; i++){
        if(i - 2 * r >= 0){
            maxim = max(maxim, d[i - 2 * r]);
        }
        d[i] = maxim + 1;
        for(j = i - 1; j > max(i - 2 * r, -1); j--){
            if(v[i].t - v[j].t >= dist(v[i], v[j]) ){
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    for(i = 0; i <= n; i++){
        maxim = max(maxim, d[i]);
    }
    cout<< maxim;
}