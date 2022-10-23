#include<iostream>
using namespace std;
int main()
{
    int n,k,i,s=0,x,c;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
         cin>>x;
         if(i<=k&&x!=0)s++;
         if(i==k)c=x;
         if(i>k&&x==c&&x!=0)s++;
    }
    cout<<s;
        
}