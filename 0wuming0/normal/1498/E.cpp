#include"bits/stdc++.h"
using namespace std;
int k[505],pos[505];
bool cmp(int x,int y)
{
    return k[x]<k[y];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",k+i);
        pos[i]=i;
    }
    sort(pos+1,pos+n+1,cmp);
    int ans=-1,ans1=0,ans2=0;
    int sum=0,des=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt++;
        sum+=k[pos[i]]-des;
        if(sum==cnt*(cnt-1)/2)
        {
            if(cnt>1&&k[pos[i]]-k[pos[i-cnt+1]]>ans)
            {
                ans=k[pos[i]]-k[pos[i-cnt+1]];
                ans1=pos[i];
                ans2=pos[i-cnt+1];
            }
            sum=0;
            des+=cnt;
            cnt=0;
        }
    }
    cout<<"! "<<ans1<<" "<<ans2<<endl;
    return 0;
}