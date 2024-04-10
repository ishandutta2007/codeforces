#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll mod=1e9+7;
ll T,A=0,B=0,C=0,a[51],b[51],c[51],d[51][51][51][3],cd[51][51][51],factor[51],F[51][51][2501],G[51][2501],TG[51][2501],TF[51][51][2501];
void read()
{
    int n,t,g;
    cin>>n>>T;
    for (int i=1;i<=n;i++)
    {
        cin>>t>>g;
        if (g==1)
        {
            A++;
            a[A]=t;
        }
        else if (g==2)
        {
            B++;
            b[B]=t;
        }
        else
        {
            C++;
            c[C]=t;
        }
    }
}

void dp()
{
    d[1][0][0][0]=d[0][1][0][1]=d[0][0][1][2]=1;
    for (int i=0;i<=A;i++)
        for (int j=0;j<=B;j++)
            for (int t=0;t<=C;t++)
            if (i+j+t>1)
            {
                if (i) d[i][j][t][0]=(d[i-1][j][t][1]+d[i-1][j][t][2])%mod;
                if (j) d[i][j][t][1]=(d[i][j-1][t][0]+d[i][j-1][t][2])%mod;
                if (t) d[i][j][t][2]=(d[i][j][t-1][0]+d[i][j][t-1][1])%mod;
            }
    factor[0]=1;
    for (int i=1;i<=A+B+C;i++) factor[i]=(factor[i-1]*i)%mod;
    for (int i=0;i<=A;i++)
        for (int j=0;j<=B;j++)
            for (int t=0;t<=C;t++)
            {
                for (int z=0;z<=2;z++) cd[i][j][t]=(cd[i][j][t]+d[i][j][t][z])%mod;
                cd[i][j][t]=(((((cd[i][j][t]*factor[i])%mod)*factor[j])%mod)*factor[t])%mod;
            }
    G[0][0]=1;
    for (int x=1;x<=C;x++)
    {
        for (int val=T-c[x];val>=0;val--)
            for (int i=1;i<=x;i++) TG[i][val+c[x]]=(G[i-1][val]+G[i][val+c[x]])%mod;
        for (int val=T;val;val--)
            for (int i=1;i<=x;i++) G[i][val]=TG[i][val];
    }
    F[0][0][0]=1;
    for (int x=1;x<=A;x++)
    {
        for (int val=T-a[x];val>=0;val--)
            for (int i=1;i<=x;i++) TF[i][0][val+a[x]]=(F[i-1][0][val]+F[i][0][val+a[x]])%mod;
        for (int val=T;val;val--)
            for (int i=1;i<=x;i++) F[i][0][val]=TF[i][0][val];
    }
    for (int x=1;x<=B;x++)
    {
        for (int val=T-b[x];val>=0;val--)
            for (int i=0;i<=A;i++)
                for (int j=1;j<=x;j++) TF[i][j][val+b[x]]=(F[i][j-1][val]+F[i][j][val+b[x]])%mod;
        for (int val=T;val;val--)
            for (int i=0;i<=A;i++)
                for (int j=1;j<=x;j++) F[i][j][val]=TF[i][j][val];
    }
    ll ans=0;
    for (int i=0;i<=A;i++)
        for (int j=0;j<=B;j++)
            for (int t=0;t<=C;t++)
                for (int val=0;val<=T;val++) ans=(ans+(((F[i][j][val]*G[t][T-val])%mod)*cd[i][j][t])%mod)%mod;
                /*{
                    cout<<F[i][j][val]<<" "<<G[t][T-val]<<" "<<cd[i][j][t]<<endl;
                }*/
    cout<<ans;
    /*for (int i=0;i<=A;i++)
        for (int j=0;j<=B;j++)
            for (int t=0;t<=C;t++) cout<<i<<" "<<j<<" "<<t<<" "<<cd[i][j][t]<<endl;*/
}
int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    dp();
    return 0;
}