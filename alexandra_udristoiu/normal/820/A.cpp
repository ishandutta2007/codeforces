#include<iostream>
using namespace std;
int nr, pg, v0, v1, c, a, l, x;
int main(){
    cin>> c >> v0 >> v1 >> a >> l;
    nr = 1;
    pg = x = v0;
    while(pg < c){
        nr++;
        x += a;
        if(x > v1){
            x = v1;
        }
        pg = pg + x - l;
    }
    cout<< nr;
    return 0;
}