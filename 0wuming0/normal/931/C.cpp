#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[10]={0};
    int f;
    cin>>f;
    a[5]++;
    for(int i=1;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        a[t-f+5]++;
    }
    int *p=a+5;
    if(a[3])p=a+3,f-=2;
    else if(a[4])p=a+4,f--;
    if(p[2]==0)
    {
        cout<<n<<endl;
        while(p[1]--)printf("%d ",f+1);
        while(p[0]--)printf("%d%c",f," \n"[p[0]==0]);
        return 0;
    }
    int ans[3]={0};
    ans[0]=p[0];ans[1]=p[1];ans[2]=p[2];
    int mm=min(ans[0],ans[2]);
    ans[1]+=2*mm;
    ans[0]-=mm;
    ans[2]-=mm;
    int best[4];
    best[0]=ans[0];
    best[1]=ans[1];
    best[2]=ans[2];
    best[3]=min(ans[0],p[0])+min(ans[1],p[1])+min(ans[2],p[2]);
    for(;ans[1]>=0;ans[1]-=2,ans[0]++,ans[2]++)
    {
        int ansss=min(ans[0],p[0])+min(ans[1],p[1])+min(ans[2],p[2]);
        if(ansss<best[3])
        {
            best[3]=ansss;
            best[0]=ans[0];
            best[1]=ans[1];
            best[2]=ans[2];
        }
    }
    cout<<best[3]<<endl;
    while(best[2]--)printf("%d ",f+2);
    while(best[1]--)printf("%d ",f+1);
    while(best[0]--)printf("%d%c",f," \n"[best[0]==0]);
    return 0;
}