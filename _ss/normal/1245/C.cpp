#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
string s;
ll f[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int check=0;
    for (int i=0;i<s.length();i++)
        if (s[i]=='m' || s[i]=='w') check=1;
    if (check)
    {
        cout<<0;
        return 0;
    }
    f[0]=f[1]=1;
    for (int i=2;i<=s.length();i++)
        if ((s[i-1]=='u' && s[i-2]=='u') || (s[i-1]=='n' && s[i-2]=='n')) f[i]=(f[i-1]+f[i-2])%mod;
        else f[i]=f[i-1];
    cout<<f[s.length()];
    return 0;
}