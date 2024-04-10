#include <bits/stdc++.h>
using namespace std;
int n,k,q,x,a[5500];
map <int,int> m;
int main()
{ 
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=k;j++)
            m[a[i]*j]=j;
    }   
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int r=1e9;
        cin>>x;
        for(int j=0;j<n;j++)
            for(int p=1;p<=k;p++)
            {
                int e=x-a[j]*p;
                if(m[e] || e==0)
                    r=min(r,p+m[e]);
            }   
        if(r<=k)
            cout<<r<<endl;
        else
            cout<<-1<<endl; 
    }
    return 0;
}