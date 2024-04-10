#include<iostream>
using namespace std;
int n, i, x, ii;
int ff[25];
long long sum;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        for(ii = 19; ii >= 0; ii--){
            if( ( (x >> ii) & 1) == 1){
                ff[ii]++;
            }
        }
    }
    for(i = 1; i <= n; i++){
        x = 0;
        for(ii = 0; ii <= 19; ii++){
            if(ff[ii] != 0){
                x += (1 << ii);
                ff[ii]--;
            }
        }
        sum += x * 1LL * x;
    }
    cout<< sum;
}