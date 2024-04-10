#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[10005],b[10005];
int c[10005];
int main()
{
    //*
    //cout<<(1<<30)<<endl;
    int n,k;
    cin>>n>>k;
    int p=0,q=(1<<30)-1;
    for(int i=2;i<=n;i++)
    {
        cout<<"and 1 "<<i<<endl;
        cin>>a[i];
        cout<<"or 1 "<<i<<endl;
        cin>>b[i];
        for(int j=0;j<30;j++)
        {
            int aa=0,bb=0;
            if(a[i]&(1<<j))aa=1;
            if(b[i]&(1<<j))bb=1;
            if(aa==bb)
            {
                if(aa)
                {
                    p|=(1<<j);
                    q|=(1<<j);
                }
                else
                {
                    p&=((1<<30)-1-(1<<j));
                    q&=((1<<30)-1-(1<<j));
                }
            }
        }
    }
    cout<<"and 2 3"<<endl;
    int r;
    cin>>r;
    for(int j=0;j<30;j++)
    {
        int aa=0,bb=0;
        if(p&(1<<j))aa=1;
        if(q&(1<<j))bb=1;
        if(aa!=bb)
        {
            if(r&(1<<j))
            {
                //
            }
            else
            {
                p+=(1<<j);
            }
        }
    }
    c[1]=p;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<30;j++)
        {
            if((a[i]&(1<<j))==(b[i]&(1<<j)))
            {
                if(a[i]&(1<<j))
                {
                    c[i]+=(1<<j);
                }
            }
            else
            {
                if(c[1]&(1<<j))
                {
                    //
                }
                else
                {
                    c[i]+=(1<<j);
                }
            }
        }
    }//*/
    sort(c+1,c+1+n);
    cout<<"finish "<<c[k]<<endl;
    return 0;
}