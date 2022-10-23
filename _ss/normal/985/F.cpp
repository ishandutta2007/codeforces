#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+10,base=29,mod=1e9+7;
ll n,m,s[maxn][27],powb[maxn];

void read()
{
    cin>>n>>m;
    char ch=getchar();
    for (int i=1;i<=n;i++)
    {
        ch=getchar();
        for (int j=1;j<=26;j++) s[i][j]=(s[i-1][j]*base+1)%mod;
        s[i][ch-'a'+1]=(s[i][ch-'a'+1]+1)%mod;
    }
}

ll gethash(int t,int l,int r)
{
    return ((s[r][t]-s[l-1][t]*powb[r-l+1]+mod*mod)%mod);
}

void process()
{
    powb[0]=1;
    for (int i=1;i<=n;i++) powb[i]=(powb[i-1]*base)%mod;
    int x,y,len;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&len);
        vector<ll> tmp1,tmp2;
        for (int j=1;j<=26;j++) tmp1.pb(gethash(j,x,x+len-1));
        for (int j=1;j<=26;j++) tmp2.pb(gethash(j,y,y+len-1));
        sort(tmp1.begin(),tmp1.end());
        sort(tmp2.begin(),tmp2.end());
        int check=1;
        for (int j=0;j<26;j++)
            if (tmp1[j]!=tmp2[j]) check=0;
        if (check) printf("YES\n"); else printf("NO\n");
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}