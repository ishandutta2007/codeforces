#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;
char a[N];
int n,mark[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cout.tie(0);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%s",(a+1));
        n=strlen(a+1);
        for (int i=1;i<=n;i++) mark[i]=0;
        for (int i=1;i<=n-4;i++)
            if (a[i]=='t' && a[i+1]=='w' && a[i+2]=='o' && a[i+3]=='n' && a[i+4]=='e') mark[i+2]=1;
        for (int i=1;i<=n-2;i++)
            if (a[i]=='t' && a[i+1]=='w' && a[i+2]=='o' && !mark[i+2]) mark[i+1]=1;
        for (int i=1;i<=n-2;i++)
            if (a[i]=='o' && a[i+1]=='n' && a[i+2]=='e' && !mark[i]) mark[i+1]=1;
        vector<int> ans;
        for (int i=1;i<=n;i++)
            if (mark[i]) ans.pb(i);
        cout<<ans.size()<<"\n";
        for (int x : ans) cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}