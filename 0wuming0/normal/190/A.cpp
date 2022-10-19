#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n+m==0)cout<<0<<" "<<0<<endl;
    else if(n==0)cout<<"Impossible"<<endl;
    else if(m==0)cout<<n<<" "<<n<<endl;
    else cout<<max(m,n)<<" "<<n+m-1<<endl;
    return 0;
}