#include<iostream>
#define DIM 300005
using namespace std;
int i, n, v[DIM];
long long nr1, nr2, dif, sum[DIM], nr3;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    for(i = n; i >= 1; i--){
        nr1 += v[i] / 2;
        nr2 = min(nr1, nr2 + v[i] % 2);
        nr3 = nr2 + sum[i - 1];
        if(nr1 > nr3){
            dif = (nr1 - nr3) / 3;
            if( (nr1 - nr3) % 3 != 0){
                dif++;
            }
            cout<< nr1 - dif;
            return 0;
        }
    }
    cout<< nr1;
}