#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
int n,a[maxn],b[maxn];
char s[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>(s+1);
    for (int i=1;i<=n;i++) cin>>b[i]>>a[i];
    int res=0;
    for (int i=1;i<=n;i++) res+=(s[i]=='1');
    for (int i=1;i<=1e4;i++)
    {
        int kq=0;
        for (int j=1;j<=n;j++)
            if (i<a[j])
            {
                if (s[j]=='1') kq++;
            }
            else if ((((i-a[j])/b[j]) & 1)==(s[j]-'0')) kq++;
        res=max(res,kq);
    }
    cout<<res;
    return 0;
}