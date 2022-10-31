#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
bool mark[1111];
int main()
{ 
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        mark[a]=mark[b]=1;
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
        {
            a=i;
            break;
        }
    cout<<n-1<<endl;
    for(int i=1;i<=n;i++)
        if(i!=a)
            cout<<i<<" "<<a<<endl;  
    return 0;
}