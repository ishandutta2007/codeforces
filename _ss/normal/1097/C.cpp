#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=5e5+1,msiz=2,mod=1e9+7,inf=1e18;
int n,a[maxn],b[maxn];
string s;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        int t=0,m=0;
        for (int i=0;i<s.length();i++)
            if (s[i]=='(') t++;
            else
            {
                t--;
                m=min(m,t);
            }
        if (t>=0 && m>=0) a[t]++;
        else if (m==t) b[-t]++;
    }
    int ans=a[0]/2;
    for (int i=1;i<maxn;i++) ans+=min(a[i],b[i]);
    cout<<ans;
    return 0;
}