#include"bits/stdc++.h"
using namespace std;
#define ll long long
int k,d;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>d>>k;
        int p=(int)(d/sqrt(2)/k);
        ll a=p*(ll)k,b=d*(ll)d;//cout<<a<<endl;
        if((a+k)*(a+k)+a*a<=b)cout<<"Ashish"<<endl;
        else cout<<"Utkarsh"<<endl;
    }
    return 0;
}