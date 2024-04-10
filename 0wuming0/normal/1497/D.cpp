#include"bits/stdc++.h"
using namespace std;
#define ll long long
//int r1[5005],r2[5005],l2[5005],l1[5005];
//ll ans[5005][5005];
ll ans1[5005];
ll ans2[5005];
ll last1[5005];
ll last2[5005];
int tag[5005];
ll s[5005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n+1;i++)
        {
            //r1[i]=r2[i]=l2[i]=l1[i]=0;
            //for(int j=0;j<=n;j++)ans[i][j]=0;
            last2[i]=last1[i]=ans1[i]=ans2[i]=0;
        }
        for(int i=1;i<=n;i++)scanf("%d",tag+i);
        for(int i=1;i<=n;i++)scanf("%lld",s+i);/*
        r1[1]=1;l1[1]=1;
        for(int i=2;i<=n;i++)
        {
            r1[i]=r1[i-1];
            l1[i]=l1[i-1];
            if(s[i]>s[r1[i]])r1[i]=i;
            if(s[i]<s[l1[i]])l1[i]=i;
        }
        r1[1]=1;l2[1]=1;
        for(int i=2;i<=n;i++)
        {
            r2[i]=r2[i-1];
            l2[i]=l2[i-1];
            for(int j=1;j<=i;j++)
            {
                if(tag[r1[i]]==tag[r2[i]])r2[i]=j;
                if(tag[l1[i]]==tag[l2[i]])l2[i]=j;
                if(tag[j]!=tag[r1[i]]&&s[j]>s[r2[i]])r2[i]=j;
                if(tag[j]!=tag[l1[i]]&&s[j]<s[l2[i]])l2[i]=j;
            }
        }*/
        ll sum=0;
        for(int i=n;i>=1;i--)
        {
            if(i==n)
            {
                if(tag[n]!=tag[1])ans2[1]=abs(s[n]-s[1]);
                for(int j=2;j<n;j++)
                {
                    ans2[j]=ans2[j-1];
                    if(tag[n]!=tag[j])ans2[j]=max(ans2[j],abs(s[n]-s[j]));
                }
                for(int j=1;j<n;j++)if(tag[j]!=tag[n])ans1[j]=ans2[j-1]+abs(s[j]-s[n]);
                for(int j=1;j<=n;j++){sum=max(sum,ans1[j]);sum=max(sum,ans2[j]);}
                //for(int j=1;j<=n;j++)printf("%lld%c",ans1[j]," \n"[j==n]);
                //for(int j=1;j<=n;j++)printf("%lld%c",ans2[j]," \n"[j==n]);
                continue;
            }
            //ans1[i] ans2[i]
            /*
            for(int j=n;j>i;j--)
            {
                if(j!=n)ans[i][j]=ans[i][j+1];
                if(tag[i]!=tag[j])
                {
                    ans[i][j]=max(ans[i][j],ans[j][i-1]+abs(s[i]-s[j]));
                }
            }*/
            for(int j=1;j<i;j++)
            {
                if(j==1)ans2[1]=ans1[i];
                if(j!=1)ans2[j]=ans2[j-1];
                if(tag[i]!=tag[j])
                {
                    ans2[j]=max(ans2[j],ans1[j]+abs(s[i]-s[j]));
                }
            }
            for(int j=1;j<i;j++)if(tag[j]!=tag[i])
            {
                ans1[j]=max(max(ans2[j-1],ans1[i])+abs(s[j]-s[i]),ans1[j]);
            }
            //for(int j=1;j<i;j++)ans1[j][i]=max(ans[j][i],ans[j][i+1]);
            //
            //for(int j=1;j<=n;j++)printf("%lld%c",ans1[j]," \n"[j==n]);
            //for(int j=1;j<=n;j++)printf("%lld%c",ans2[j]," \n"[j==n]);
            //putchar(10);
            for(int j=1;j<=n;j++){sum=max(sum,ans1[j]);sum=max(sum,ans2[j]);}
        }


        //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)sum=max(sum,ans[i][j]);

        //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%lld%c",ans[i][j]," \n"[j==n]);
        cout<<sum<<endl;
    }
    return 0;
}