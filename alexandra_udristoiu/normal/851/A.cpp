#include<iostream>
using namespace std;
int n, k, t, st, dr;
int main(){
    cin>> n >> k >> t;
    dr = min(n, t);
    st = max(t - k, 0);
    cout<< dr - st;
    return 0;
}