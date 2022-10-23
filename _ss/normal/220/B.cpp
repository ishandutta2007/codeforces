#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1,k=500;
int a[maxn],n,q,dd[maxn],cnt[maxn][k];
vector<int> b;
void read()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void process()
{
    for (int i=1;i<=n;i++)
     if (a[i]<=n) dd[a[i]]++;
     for (int i=1;i<=n;i++)
        if (dd[i]>=i) b.pb(i);
     for (int i=1;i<=n;i++)
        for (int j=0;j<b.size();j++)
        if (b[j]==a[i]) cnt[i][j]=cnt[i-1][j]+1; else cnt[i][j]=cnt[i-1][j];
     int l,r;
     for (int i=1;i<=q;i++)
     {
         cin>>l>>r;
         int counted=0;
         for (int j=0;j<b.size();j++)
            if (cnt[r][j]-cnt[l-1][j]==b[j]) counted++;
         cout<<counted<<endl;
     }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}