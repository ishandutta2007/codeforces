#include<iostream>
#define DIM 100005
using namespace std;
int n, i, x, nr, sol;
int s[DIM], ff[DIM];
int main(){
    cin>> n >> x;
    nr = s[1] = ff[x] = sol = 1;
    for(i = 2; i <= n; i++){
        cin>> x;
        if(ff[x] == 0){
            s[1]++;
            ff[x] = 1;
            nr++;
        }
        else{
            s[ ff[x] ]--;
            ff[x]++;
            s[ ff[x] ]++;
        }
        if( (i - 1) % nr == 0 && s[ (i - 1) / nr ] == nr - 1){
            sol = i;
        }
        else{
            if(s[1] > 0 && (i - 1) % (nr - 1) == 0 && s[ (i - 1) / (nr - 1) ] >= nr - 1){
                sol = i;
            }
        }
    }
    cout<< sol;
}