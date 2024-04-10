#include<iostream>
using namespace std;
int main()
{
    int k,l,m,n,d,s,i;
    cin>>k;
    cin>>l;
    cin>>m;
    cin>>n;
    cin>>d;
    if(k==1||l==1||m==1||n==1)s=0;
    else
    {
         s=0;
         for(i=1;i<=d;i++)
         {
              if(i%k&&i%l&&i%m&&i%n)
              {
                   s++;
              }
         }
    }
    cout<<d-s<<endl;               
    
}