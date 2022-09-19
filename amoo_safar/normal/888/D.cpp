#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
int b[603];
int main(){

    ll n,k,a,b,c,d,e;
    cin >> n >> k;
    a = 1;
    b = 0;
    c =(n*(n-1))/2;
    d = (n*(n-1)*(n-2))/3;
    e=(3*n*(n-1)*(n-2)*(n-3))/8;
    if(k == 4)cout << a+b+c+d+e;
    if(k == 3)cout << a+b+c+d;
    if(k == 2)cout << a+b+c;
    if(k == 1)cout << a+b;
    return 0;
}