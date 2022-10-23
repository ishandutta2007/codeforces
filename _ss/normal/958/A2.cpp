#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll N=2e3+10,M=2e2+10,mod=1e9+7,base=31;
char a[N][M],b[M][N];
int n,m;
ll hasha[N][M],hashb[M][N],powbase[N*N];
void read()
{
    cin>>n>>m;
    char ch;
    for (int i=1;i<=n;i++)
    {
        ch=getchar();
        for (int j=1;j<=m;j++) a[i][j]=getchar();
    }
    for (int i=1;i<=m;i++)
    {
        ch=getchar();
        for (int j=1;j<=n;j++) b[i][j]=getchar();
    }
}

void build()
{
    powbase[0]=1;
    for (int i=1;i<=n*n;i++) powbase[i]=(powbase[i-1]*base)%mod;
    int t=n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) hasha[i][j]=(hasha[i-1][j]*powbase[t]+hasha[i][j-1]*base-hasha[i-1][j-1]*powbase[t+1]+(a[i][j]-'a'+1)+mod*mod)%mod;
    swap(m,n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) hashb[i][j]=(hashb[i-1][j]*powbase[t]+hashb[i][j-1]*base-hashb[i-1][j-1]*powbase[t+1]+(b[i][j]-'a'+1)+mod*mod)%mod;
    swap(m,n);
}

ll gethasha(ll x)
{
    return (hasha[x+m-1][m]-hasha[x-1][m]*powbase[m*n]+mod*mod)%mod;
}

ll gethashb(ll x)
{
    return (hashb[m][x+m-1]-hashb[m][x-1]*powbase[m]+mod*mod)%mod;
}

void process()
{
    for (int i=1;i<=n-m+1;i++)
        for (int j=1;j<=n-m+1;j++)
            if (gethasha(i)==gethashb(j))
            {
                cout<<i<<" "<<j;
                return;
            }
    for (int i=1;i<=n-m+1;i++)
    {
        cout<<gethasha(i)<<" "<<gethashb(i)<<endl;
    }
    /*for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cout<<hasha[i][j]<<" "; cout<<endl;}*/
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    build();
    process();
    return 0;
}