#include<iostream>
#define DIM 8000000
using namespace std;
int k, n, sol, x, i, j;
int a[2005], b[2005], s[2005];
short nr[2 * DIM + 5], lst[2 * DIM + 5];
int main(){
    cin>> k >> n;
    for(i = 1; i <= k; i++){
        cin>> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(i = 1; i <= n; i++){
        cin>> b[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= k; j++){
            x = b[i] - s[j];
            if(lst[x + DIM] != i){
                nr[x + DIM]++;
                lst[x + DIM] = i;
            }
        }
    }
    for(i = 0; i <= DIM + DIM; i++){
        if(nr[i] == n){
            sol++;
        }
    }
    cout<< sol;
    return 0;
}