#include<iostream>
#define DIM 100005
using namespace std;
int n, i, k, st, dr, t, p, nr;
int sol[2 * DIM];
char a[DIM], b[DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> a + 1;
        cin>> b + 1;
        k = 0;
        st = 1;
        dr = n;
        nr = 0;
        for(i = n; i >= 1; i--){
            if(nr % 2 == 0){
                p = a[st];
            }
            else{
                p = '0' + '1' - a[dr];
            }
            if(p == b[i]){
                sol[++k] = 1;
            }
            sol[++k] = i;
            nr++;
            if(nr % 2 == 1){
                st++;
            }
            else{
                dr--;
            }
        }
        cout<< k <<" ";
        for(i = 1; i <= k; i++){
            cout<< sol[i] <<" ";
        }
        cout<<"\n";
    }
}