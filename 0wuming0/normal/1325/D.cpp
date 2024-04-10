#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a,b;
int main()
{
    cin>>a>>b;
    if(b<a)cout<<"-1"<<endl;
    else if((a+b)%2)cout<<"-1"<<endl;
    else if(a+b==0)cout<<"0"<<endl<<endl;
    else if(a==b)cout<<1<<endl<<a<<endl;
    else
    {
        ll c=b-a;
        c/=2;
        if((c^a)==c+a)cout<<2<<endl<<a+c<<" "<<c<<endl;
        else cout<<3<<endl<<a<<" "<<c<<" "<<c<<endl;
    }
    return 0;
}