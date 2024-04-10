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
const ll N=4e6+10,mod=1e9+7,inf=1e18;
ll a[N],n;
char s[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int x;
        scanf("%d",&x);
        scanf("%s",(s+1));
        int n=strlen(s+1);
        for (int i=1;i<=n;i++) a[i]=s[i]-'0';
        ll res=n,mark=0;
        for (int i=1;i<=x;i++)
        {
            if (!mark)
            {
                for (int j=1;j<a[i];j++)
                    for (int u=i+1;u<=res;u++) a[res+u-i+(j-1)*(res-i)]=a[u];
                res=(res+(res-i)*(a[i]-1));
                if (res>=x) mark=1;
            }
            else res=(res+(res-i+mod)%mod*(a[i]-1))%mod;
        }
        cout<<res<<"\n";
    }
    return 0;
}