#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int a[N];

int ptt(int x,int k)
{
    return (x+k)%n;
}

int pp(int x)
{
    if(x==n-1)
        return 0;
    return x+1;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int minu=a[0];
    for(int i=1;i<n;++i)
        minu=min(minu,a[i]);
    for(int i=0;i<n;++i)
        a[i]-=minu;
    int x=0;
    x=ptt(x,minu);
    for(int k=0;;x=pp(x),++k)
    {
        a[x]-=k;
        if(a[x]<=0)
        {
            cout<<x+1<<endl;
            return 0;
        }
    }
    return 0;
}