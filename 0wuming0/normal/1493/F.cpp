#include"bits/stdc++.h"
using namespace std;
int ans;
int n,m;
int maxask,nowask;
int ask(int a,int c,int d,int op)
{
    nowask++;
    if(nowask>maxask)exit(1);
    int t;
    int h,w,i1,j1,i2,j2;
    if(op==1)
    {
        w=d;
        h=n;
        i1=i2=1;
        j1=a;
        j2=c;
    }
    else
    {
        w=m;
        h=d;
        j1=j2=1;
        i1=a;
        i2=c;
    }
    cout<<"? "<<h<<" "<<w<<" "<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
    cin>>t;
    return t;
}
int prime[1005];
int solve(int l,int r,int len,int d,int op)
{
    return ask(l*d-d+1,r*d-d+1,d*len,op);
}
int check(int num,int d,int op)
{//cout<<num<<endl;
    int flag=1;
    flag=min(solve(1,2,1,d,op),flag);
    int now=2;
    if(num==2)return flag;
    while(1)
    {
        if(now*2<=num)
        {
            flag=min(solve(1,now+1,now,d,op),flag);
            now*=2;
        }
        else
        {
            if(now!=num)
            {
                flag=min(solve(1,now+1,num-now,d,op),flag);
            }
            break;
        }
    }
    return flag;
}
int main()
{
    //cout<<log(3)/log(2)<<endl;
    for(int i=2;i<=1000;i++)if(prime[i]==0)for(int j=2;i*j<=1000;j++)prime[i*j]=1;
    ans=1;
    int T=1000;
    //while(T--)
        {
    cin>>n>>m;
    maxask=log(n+m)/log(2)+1e-7;
    maxask*=3;
    nowask=0;
    ans=1;
    int now=n;
    int op=0;
    for(int i=2;i<=1000;i++)if(prime[i]==0&&now%i==0)
    {
        int flag2=1;
        int t=1;
        int k=i/2;
        int sum=1;
        while(now%i==0)
        {
            t*=i;
            int d=n/t;
            now/=i;
            k=d;
            int flag;//=ask(1,k+1,k,op);
            flag=check(i,d,op);
            //if(i!=2)flag=min(ask(1,2*k+1,d,op),flag);
            if(flag&&flag2)sum++;
            else flag2=0;
        }
        ans*=sum;
    }//cout<<"ok"<<endl;
    now=m;
    op=1;
    for(int i=2;i<=1000;i++)if(prime[i]==0&&now%i==0)
    {
        int flag2=1;
        int t=1;
        int k=i/2;
        int sum=1;
        while(now%i==0)
        {
            t*=i;
            int d=m/t;
            now/=i;
            k=d;
            int flag;//=ask(1,k+1,k,op);
            flag=check(i,d,op);
            //if(i!=2)flag=min(ask(1,2*k+1,d,op),flag);
            if(flag&&flag2)sum++;
            else flag2=0;
        }
        ans*=sum;
    }
    cout<<"! "<<ans<<endl;}
    return 0;
}