#include <iostream>

using namespace std;

int h(int a, int b, int m){
    long long e=1;
    for(int i=1;i<=b;i++){
        e*=a;
        e%=m;
    }
    return e;
}

int main()
{
    int n;
    cin>>n;
    cout<<(h(3,3*n,1000000007)-h(7,n,1000000007)+1000000007)%1000000007<<endl;
    return 0;
}