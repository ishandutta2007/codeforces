#include<iostream>
using namespace std;
int n, m, k, a, b, r, ok;
int main(){
    cin>> n >> m >> k;
    if( (2LL * n * m) % k != 0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    if(k % 2 == 0){
        k /= 2;
        ok = 1;
    }
    a = n;
    b = k;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    n /= a;
    k /= a;
    m /= k;
    if(ok == 0){
        if(a != 1){
            n *= 2;
        }
        else{
            m *= 2;
        }
    }
    cout<<"0 0\n"<< n <<" 0\n"<<"0 "<< m <<"\n";
}