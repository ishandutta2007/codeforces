#include<iostream>
using namespace std;
long long n, st, dr, mid;
int verif(long long val){
    long long m = n, sum = 0;
    while(m > val){
        sum += val;
        m -= val;
        m -= m / 10;
    }
    sum += m;
    if(sum >= n / 2 + n % 2){
        return 1;
    }
    return 0;
}
int main(){
    cin>> n;
    st = 1;
    dr = n;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(verif(mid)){
            dr = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    cout<< st;
}