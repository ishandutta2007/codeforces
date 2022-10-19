#include"bits/stdc++.h"
using namespace std;
int n;
int a[100006];
int m=1e9,pos;
int qt=100;
int qu(int i)
{
    if(a[i]!=0)return a[i];
    cout<<"? "<<i<<endl;
    cout.flush();
    int t;
    cin>>t;
    a[i]=t;
    if(m>t)
    {
        m=t;
        pos=i;
        if(a[i-1]!=0&&a[i+1]!=0)
        {
            cout<<"! "<<i<<endl;
            exit(0);
        }
    }
    qt--;
    return t;
}
void solve(int l,int r)
{
    if(qt>=r-l+1)
    {
        for(int i=l;i<=r;i++)qu(i);
        cout<<"! "<<pos<<endl;
        exit(0);
    }
    int x=(l+r)/2;
    qu(x);
    qu(x+1);
    if(x+1<=pos&&pos<=r)solve(x+1,r);
    else solve(l,x);
}
int main()
{
    cin>>n;
    a[0]=1e9;
    a[n+1]=1e9;
    solve(1,n);
    return 0;
}