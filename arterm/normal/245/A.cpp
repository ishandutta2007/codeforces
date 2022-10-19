#include <iostream>

using namespace std;

long n,x[10],y[10],a,t,b;

int main()
{
    cin>>n;
    while (n--){
        cin>>t>>a>>b;
        x[t]+=a;
        y[t]+=b;
    }
    x[1]>=y[1] ? cout<<"LIVE\n":cout<<"DEAD\n";
    x[2]>=y[2] ? cout<<"LIVE\n":cout<<"DEAD\n";
    return 0;
}