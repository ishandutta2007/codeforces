#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int n,q;
    cin>>n>>q;
    int num=0;
    for(int i=0;i<n;i++)
    {scanf("%d",a+i);num+=a[i];
    }
    while(q--)
    {
        int p,c;
        cin>>p>>c;
        if(p==2)
        {
            if(c<=num)cout<<1<<endl;
            else cout<<0<<endl;
        }
        else
        {
            num-=a[c-1];
            a[c-1]^=1;
            num+=a[c-1];
        }
    }
    return 0;
}