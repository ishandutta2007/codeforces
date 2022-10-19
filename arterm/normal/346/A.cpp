#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int x, int y){
    while (x){
        y%=x;
        swap(x,y);
    }
    return y;
}

int main(void){
    int n,m,a,d;
    cin>>n>>d;
    m=d;
    for (int i=1; i<n; ++i){
        cin>>a;
        m=max(a,m);
        d=gcd(d,a);
    }
    int sum=m/d-n;
    if (sum%2==0)
        cout<<"Bob\n";
    else
        cout<<"Alice\n";
    return 0;
}