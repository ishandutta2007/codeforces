#include"bits/stdc++.h"
using namespace std;
int a[105];
int save1[105],nn1;
int save2[105],nn2;
int save3[105],nn3;
int save4[105],nn4;
int main()
{
    int n;
    cin>>n;
    int bb=n/2;
    int aa=n-bb;
    int ans=0;
    int last=0,li=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if(a[i]==0)continue;
        if(a[i]%2)
        {
            aa--;
            if(li==-1)save3[nn3++]=i;
            else if(last%2==0)
            {
                ans++;
            }
            else
            {
                save1[nn1++]=i-li-1;
            }
            last=a[i];
            li=i;
        }
        else
        {
            bb--;
            if(li==-1)save4[nn4++]=i;
            else if(last%2==0)
            {
                save2[nn2++]=i-li-1;
            }
            else
            {
                ans++;
            }
            last=a[i];
            li=i;
        }
    }
    if(li==-1)
    {
        cout<<(n!=1)<<endl;
        return 0;
    }
    else
    {
        if(last%2)save3[nn3++]=n-li-1;
        else save4[nn4++]=n-li-1;
    }
    ans+=nn1*2+nn2*2+nn3+nn4;
    int ans1=0,ans2=0;
    int sum1=0,sum2=0;
    sort(save1,save1+nn1);
    sort(save2,save2+nn2);
    sort(save3,save3+nn3);
    sort(save4,save4+nn4);
    save3[nn3]=1000;
    save4[nn4]=1000;/*
    cout<<ans<<endl;
    cout<<aa<<" "<<bb<<endl;
    cout<<"<<<"<<1<<endl;
    for(int i=0;i<nn1;i++)printf("%d%c",save1[i]," \n"[i==nn1-1]);cout<<"<<<"<<2<<endl;
    for(int i=0;i<nn2;i++)printf("%d%c",save2[i]," \n"[i==nn2-1]);cout<<"<<<"<<3<<endl;
    for(int i=0;i<nn3;i++)printf("%d%c",save3[i]," \n"[i==nn3-1]);cout<<"<<<"<<4<<endl;
    for(int i=0;i<nn4;i++)printf("%d%c",save4[i]," \n"[i==nn4-1]);*/
    if(aa>=save3[0]+save3[1])ans1=max(sum1+2,ans1);
        else if(aa>=save3[0])ans1=max(sum1+1,ans1);
        else ans1=max(sum1,ans1);
    for(int i=0;i<nn1;i++)
    {
        if(aa>=save1[i])
        {
            aa-=save1[i];
            sum1+=2;
        }
        if(aa>=save3[0]+save3[1])ans1=max(sum1+2,ans1);
        else if(aa>=save3[0])ans1=max(sum1+1,ans1);
        else ans1=max(sum1,ans1);
    }
    if(bb>=save4[0]+save4[1])ans2=max(sum2+2,ans2);
        else if(bb>=save4[0])ans2=max(sum2+1,ans2);
        else ans2=max(sum2,ans2);
    for(int i=0;i<nn2;i++)
    {
        if(bb>=save2[i])
        {
            bb-=save2[i];
            sum2+=2;
        }
        if(bb>=save4[0]+save4[1])ans2=max(sum2+2,ans2);
        else if(bb>=save4[0])ans2=max(sum2+1,ans2);
        else ans2=max(sum2,ans2);
    }
    //cout<<ans1<<" "<<ans2<<endl;
    cout<<ans-ans1-ans2<<endl;
    return 0;
}
/*
1
0

2
0 0
*/