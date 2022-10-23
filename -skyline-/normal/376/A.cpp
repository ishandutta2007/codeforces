#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    long long r=0;
    int m,i,l;
    string x;
    cin>>x;
    l=x.size();
    for(i=0;i<l;i++)if(x[i]=='^')m=i,i=l+1;
    for(i=0;i<l;i++)
    {
         if(x[i]!='=')
         {
              r+=(m-i)*(x[i]-48);
         }
    }
    if(r<0)cout<<"right";
    if(r>0)cout<<"left";
    if(r==0)cout<<"balance";
    cout<<endl;
}