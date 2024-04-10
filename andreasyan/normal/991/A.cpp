#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if(b<c || a<c)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    b-=c;
    if(n-(a+b)<1)
        cout<<-1<<endl;
    else
        cout<<n-(a+b)<<endl;
    return 0;
}