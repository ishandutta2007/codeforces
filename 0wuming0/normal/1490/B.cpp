#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int num[3]={0};
        for(int i=0;i<n;i++)
        {
            int c;
            scanf("%d",&c);
            num[c%3]++;
        }
        while(num[0]<num[1]||num[0]<num[2])
        {
            swap(num[0],num[1]);
            swap(num[1],num[2]);
        }
        int ans=0;
        int s=n/3;
        if(num[2]>s)
        {
            ans+=num[2]-s;
            num[0]+=num[2]-s;
            num[2]=s;
        }
        if(num[0]>s)
        {
            ans+=num[0]-s;
            num[1]+=num[0]-s;
            num[0]=s;
        }
        if(num[1]>s)
        {
            ans+=num[1]-s;
        }
        cout<<ans<<endl;
    }
    return 0;
}