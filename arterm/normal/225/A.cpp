#include <iostream>

using namespace std;

long thi(long a,long b){
    if (a>3)
    a=7-a;
    if (b>3)
    b=7-b;
    for (long i=1; i<=3; ++i)
    if (a!=i && b!=i)
    return i;
}

int main()
{
    long n,u,a,b,t;
    cin>>n>>u;
    u=7-u;
    for (long i=0; i<n; ++i){
        cin>>a>>b;
        t=thi(a,b);
        if (t!=u && t!=7-u){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}