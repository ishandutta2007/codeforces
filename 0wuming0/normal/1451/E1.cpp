#include"bits/stdc++.h"
using namespace std;
#define ll long long
int x[70000];
int main()
{
    int n;
    cin>>n;
    int a0,b0,c0,ans[20];
    cout<<"AND 1 2"<<endl;
    cin>>a0;
    cout<<"AND 1 3"<<endl;
    cin>>b0;
    cout<<"AND 2 3"<<endl;
    cin>>c0;
    cout<<"XOR 1 2"<<endl;
    cin>>x[2];
    cout<<"XOR 1 3"<<endl;
    cin>>x[3];
    for(int i=0;i<20;i++)
    {
        int p=(1<<i);
        int a=(a0&p),b=(b0&p),c=(x[2]&p),d=(x[3]&p),e=(c0&p);
        if(a>0||b>0)ans[i]=1;
        else if(c==0||d==0)ans[i]=0;
        else
        {
            if(e==0)ans[i]=1;
            else ans[i]=0;
        }
    }
    int z=0;
    for(int i=19;i>=0;i--)z=2*z+ans[i];
    for(int i=4;i<=n;i++)
    {
        cout<<"XOR 1 "<<i<<endl;
        cin>>x[i];
    }
    x[1]=z;
    for(int i=2;i<=n;i++)
    {
        x[i]^=x[1];
    }
    cout<<"!";
    for(int i=1;i<=n;i++)cout<<" "<<x[i];
    cout<<endl;
    return 0;
}