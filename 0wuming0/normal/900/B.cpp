#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=1e7;i++)
    {
        a*=10;
        if(a/b==c)
        {
            cout<<i<<endl;
            return 0;
        }
        a%=b;
    }
    cout<<-1<<endl;
    return 0;
}