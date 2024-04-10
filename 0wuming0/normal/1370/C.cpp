#include"bits/stdc++.h"
using namespace std;
int prime(int n)
{
    int m=min((int)sqrt(n+1),n-1);
    for(int i=2;i<=m;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)cout<<"FastestFinger"<<endl;
        else if(n<=3)cout<<"Ashishgup"<<endl;
        else if(n%2)cout<<"Ashishgup"<<endl;
        else if(n%4==0)
        {
            while(n%2==0)n/=2;
            if(n==1)cout<<"FastestFinger"<<endl;
            else cout<<"Ashishgup"<<endl;
        }
        else
        {
            if(prime(n/2))cout<<"FastestFinger"<<endl;
            else cout<<"Ashishgup"<<endl;
        }
    }
    return 0;
}