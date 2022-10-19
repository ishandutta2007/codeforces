#include"bits/stdc++.h"
using namespace std;
#define ll long long
int k;
int cal(int x,int y)
{
    int ans=0;
    for(int i=1;x>0||y>0;i*=k)
    {
        ans+=(x%k+y%k)%k*i;
        x/=k;
        y/=k;
    }
    return ans;
}
int sum[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        int last=0;
        int op;
        for(int i=0;i<n;i++)
        {
            if(i)last=cal(i,sum[i-1]);
            cout<<last<<endl;
            cin>>op;
            if(op==1)
            {
                break;
            }
            if(i)sum[i]=cal(last,sum[i-1]);
        }
    }
    return 0;
}