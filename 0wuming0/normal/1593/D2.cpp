#include"bits/stdc++.h"
using namespace std;
int a[55];
int save[2000006];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)a[i]+=1000000;
        int ans=1,temp;
        vector<int>v;
        for(int i=2;i<=1000001;i++)v.push_back(i);
        v.push_back(2000006);
        for(auto i:v)
        {
            for(int j=0;j<n;j++)
            {
                save[temp=a[j]%i]++;
                if(save[temp]>=(n>>1))ans=i;
            }
            for(int j=0;j<n;j++)save[a[j]%i]--;
        }
        for(int i=0;i<n;i++)save[a[i]]++;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(a[i]!=a[j]&&save[a[i]]+save[a[j]]>=(n>>1))
        {
            ans=max(abs(a[i]-a[j]),ans);
        }
        for(int i=0;i<n;i++)save[a[i]]=0;
        if(ans==2000006)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}