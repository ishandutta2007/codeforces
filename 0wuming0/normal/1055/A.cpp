#include"bits/stdc++.h"
using namespace std;
int a[1005];
int b[1005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int flag=0;
    for(int i=m;i<n;i++)if(a[i]==1&&b[i]==1)flag=1;
    if(a[0]==1&&(a[m-1]==1||(b[m-1]&&flag)))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}