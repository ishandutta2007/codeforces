#include<iostream>
using namespace std;
int t, n, g, b, i;
long long st, dr, mid;
long long calc(long long x){
    return (x / b) * g + min(g * 1LL, x % b);
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> g >> b;
        b += g;
        st = n;
        dr = b * 1LL * n;
        while(st <= dr){
            mid = (st + dr) / 2;
            if( calc(mid) >= n / 2 + n % 2){
                dr = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        cout<< st <<"\n";
    }
}