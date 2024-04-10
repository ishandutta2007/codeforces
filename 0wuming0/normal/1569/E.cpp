#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
int ans[100];
int save[100][100],nn[100];
int sp[100]={1,2,3,5,9,17};
ll mul[100];
ll cmul[100];
ll k,a,h,n;
ll now;
int temp[100],ln,rn;
void solve(int sd)
{
    for(int i=0;i<k;i++)nn[i]=0;
    now=k-1;
    ln=rn=0;
    for(int i=1;i<=n;i+=2)
    {
        temp[ln++]=i;
    }
    while(1)
    {
        if(now==0)
        {
            save[now][nn[now]++]=temp[0];
            break;
        }
        for(int i=0;i<ln;i+=2)
        {
            if(sd&1)
            {
                save[now][nn[now]++]=temp[i];
                temp[rn++]=temp[i+1];
            }
            else
            {
                save[now][nn[now]++]=temp[i+1];
                temp[rn++]=temp[i];
            }
            sd>>=1;
        }
        ln=rn;rn=0;now--;
    }
    now=0;
    ll cg=0;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<nn[i];j++)
        {
            now+=mul[i]*save[i][j]%mod;//cout<<"<<<"<<save[i][j]<<" "<<i<<" "<<mul[i]<<endl;
        }
    }//cout<<"ok"<<now<<endl;
    now%=mod;
    for(int p[6]={0};;p[0]++)
    {
        int i=0;
        while(i<k&&p[i]>nn[i])
        {
            p[i]-=nn[i]+1;
            p[i+1]++;
            i++;
        }
        if(p[k])break;
        cg=now;
        for(i=0;i<k;i++)
        {
            cg+=cmul[i]*p[i]%mod;
        }
        cg%=mod;//cout<<"!!!"<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<cg<<endl;
        if(cg==h)
        {
            for(int i=0;i<k;i++)
            {
                for(int j=0;j<p[i];j++)save[i][j]++;
                for(int j=0;j<nn[i];j++)
                {
                    ans[save[i][j]]=sp[i];
                }
            }
            for(int i=1;i<=n;i++)if(ans[i]==0)ans[i]=sp[k];
            for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
            exit(0);
        }
    }
}
int main()
{
    cin>>k>>a>>h;
    ll temp=a;
    mul[0]=a;
    for(int i=1;i<=8;i++)
    {
        mul[i]=temp*a%mod;
        temp=temp*temp%mod;
    }
    n=(1<<k);
    for(int i=2;i<=n;i+=2)
    {
        save[k][nn[k]++]=i;
    }
    for(int i=0;i<k;i++)cmul[i]=(mul[i]-mul[k]+mod)%mod;//for(int i=0;i<=k;i++)printf("%lld%c",cmul[i]," \n"[i==k]);
    for(int num=0;num<(1<<15);num++)
    {
        solve(num);
    }
    cout<<-1<<endl;
    return 0;
}