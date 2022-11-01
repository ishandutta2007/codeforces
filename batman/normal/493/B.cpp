#include <iostream>
#include <stdio.h>
#include <algorithm>


using namespace std;
#define INF (1000*1000*1000)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}

ll n,a[200*1000],b[200*1000],p1,p2,sum,ex;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ex;
        sum+=ex;
        if(ex>0)
        {
            a[p1]=ex;
            p1++;
        }
        else
        {
            b[p2]=abs(ex);
            p2++;
        }
    }
    if(sum>0)
    {
        cout<<"first";
        return 0;
    }
    else if(sum<0)
    {
        cout<<"second";
        return 0;
    }
    else if(sum==0)
    {
        for(int i=0;i<min(p1,p2);i++)
        {
            if(a[i]>b[i])
            {
                cout<<"first";
                return 0;
            }
            if(a[i]<b[i])
            {
                cout<<"second";
                return 0;
            }
        }
        if(p1>p2)
        {
                cout<<"first";
                return 0;
        }
        if(p1<p2)
        {
                cout<<"second";
                return 0;
        }
        if(ex>0)
        {
                cout<<"first";
                return 0;
        }
        if(ex<0)
        {
                cout<<"second";
                return 0;
        }
        
        
    }
    
    return 0;
}