#include<iostream>
using namespace std;
int t, p, f, s, w, ns, nw, i, sol, val, x, y;
int d[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> p >> f;
        cin>> ns >> nw;
        cin>> s >> w;
        if(s > w){
            swap(s, w);
            swap(ns, nw);
        }
        sol = 0;
        for(i = 0; i <= ns; i++){
            if(i * 1LL * s > p){
                break;
            }
            x = min(ns - i, f / s);
            y = min(nw, (p - i * s) / w + (f - x * s) / w);
            sol = max(sol, x + y + i);
        }
        cout<< sol <<"\n";
    }
}