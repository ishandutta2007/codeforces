#include<iostream>
#define x first
#define y second
#define pll pair<long long, long long>
using namespace std;
int nr, i, j, sol, ii;
long long x0, y0, ax, ay, bx, by, t, xs, ys;
pll p[100];
long long modul(long long x){
    if(x > 0){
        return x;
    }
    return -x;
}
long long dist(pll a, pll b){
    return modul(a.x - b.x) + modul(a.y - b.y);
}
int main(){
    cin>> x0 >> y0 >> ax >> ay >> bx >> by;
    cin>> xs >> ys >> t;
    p[0] = make_pair(xs, ys);
    p[++nr] = make_pair(x0, y0);
    while(p[nr].x - xs + p[nr].y - ys < t){
        nr++;
        p[nr].x = p[nr - 1].x * ax + bx;
        p[nr].y = p[nr - 1].y * ay + by;
    }
    for(i = 1; i <= nr; i++){
        for(j = i; j <= nr; j++){
            for(ii = i; ii <= j; ii++){
                if( dist(p[0], p[ii]) + min(dist(p[ii], p[j]), dist(p[ii], p[i]) ) + dist(p[j], p[i]) <= t ){
                    sol = max(sol, j - i + 1);
                }
            }
        }
    }
    cout<< sol;
}