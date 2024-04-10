#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

long long a,b,x,y,z,ans=0;

int main()
{
    cin>>a>>b>>x>>y>>z;
    if(a<x*2+y)ans=x*2+y-a;
    if(b<z*3+y)ans+=z*3+y-b;
    cout<<ans<<endl;
    
    //system("pause");
    return 0;
}