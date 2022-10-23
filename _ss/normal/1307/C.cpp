#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
string s;
ll a[N],cnt[N],n;

ll cal(int x,int y)
{
    ll d=0,res=0;
    if (a[1]==x) d++;
    for (int i=2;i<=n;i++)
    {
        if (a[i]==y) res+=d;
        if (a[i]==x) d++;
    }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n=s.length();
    for (int i=1;i<=(int)s.length();i++) a[i]=s[i-1]-'a'+1,cnt[a[i]]++;
    ll res=0;
    for (int i=1;i<=26;i++) res=max(res,cnt[i]);
    for (int i=1;i<=26;i++)
        for (int j=1;j<=26;j++) res=max(res,cal(i,j));
    cout<<res;
    return 0;
}