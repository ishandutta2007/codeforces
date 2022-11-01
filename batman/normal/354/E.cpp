#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (10*1010)

struct number{
    bool mark;
    int num[3][2];
    number()
    {
        mark=0;
        for(int i=0;i<3;i++)for(int j=0;j<2;j++)num[i][j]=0;
    }
};

number dp[5][N];
int n,cnt[3][2],cnt2[20][2];

void build(int x,int now=0,int tvn=1)
{
    if(x==3)
    {
        int a=now/1000,b=now%1000;
        dp[a][b].mark=1;
        for(int i=0;i<3;i++)
            for(int j=0;j<2;j++)
                dp[a][b].num[i][j]=cnt[i][j];
        return ;
    }
    for(int i=0;i<=6;i++)
        for(int j=0;j<=6;j++)
            if(i+j<=6)
            {
                cnt[x][0]=i,cnt[x][1]=j;                
                build(x+1,now+tvn*(4*i+7*j),tvn*10);
            }       
}

bool solve(ll x,int lvl=0)
{
    if(x<1000)
    {
        if(!dp[0][x].mark)return 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<2;j++)
                cnt2[lvl*3+i][j]=dp[0][x].num[i][j];
        return 1;
    }
    int a=x%1000;
    for(int i=0;i<5;i++)
        if(dp[i][a].mark && x/1000-i>=0)
        {
            for(int p=0;p<3;p++)
                for(int q=0;q<2;q++)
                    cnt2[lvl*3+p][q]=dp[i][a].num[p][q];        
            if(solve(x/1000-i,lvl+1))
                return 1;
        }
    return 0;   
}

void out()
{
    ll numbers[6]={};
    for(ll i=0,tvn=1;i<=18;i++,tvn*=10)
    {
        int p=0;
        for(int j=0;j<cnt2[i][0];j++,p++)
            numbers[p]+=4*tvn;
        for(int j=0;j<cnt2[i][1];j++,p++)
            numbers[p]+=7*tvn;
    }
    ll sum=0;
    for(int i=0;i<6;i++)sum+=numbers[i],cout<<numbers[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    build(0);
    cin>>n;
    while(n--)
    {
        ll a;
        cin>>a;
        for(int i=0;i<20;i++)for(int j=0;j<2;j++)cnt2[i][j]=0;
        if(!solve(a)){cout<<"-1\n";continue;}
        out();
    }
    return 0;
}