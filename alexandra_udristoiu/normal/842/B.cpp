#include<iostream>
using namespace std;
int t, d, r, x, y, r2, sol, dist;
int main(){
    cin>> r >> d >> t;
    for(; t; t--){
        cin>> x >> y >> r2;
        dist = x * x + y * y;
        if(dist <= (r - r2) * (r - r2) && dist >= (r - d + r2) * (r - d + r2)){
            sol++;
        }
    }
    cout<< sol;
    return 0;
}