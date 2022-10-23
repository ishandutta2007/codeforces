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
const ll maxn=2e5+10,mod=1e9+7,inf=1e18;
char s[maxn],t[maxn];
int n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>(s+1)>>(t+1);
    int st1=0,st2=0;
    vector<pii> ans;
    for (int i=1;i<=n;i++)
        if (s[i]=='a' && t[i]=='b')
        {
            if (st1) ans.pb(mp(st1,i)),st1=0;
            else st1=i;
        }
        else if (s[i]=='b' && t[i]=='a')
        {
            if (st2) ans.pb(mp(st2,i)),st2=0;
            else st2=i;
        }
    if ((st1>0 && st2==0) || (st1==0 && st2>0)) cout<<-1;
    else
    {
        cout<<ans.size()+(st1>0)*2<<endl;
        for (int i=0;i<ans.size();i++) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
        if (st1)
        {
            cout<<st1<<" "<<st1<<endl<<st2<<" "<<st1;
        }
    }
    return 0;
}