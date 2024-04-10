#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll maxn=3e5+1;
ll t[maxn],n;
pii s[maxn];

struct ds
{
    ll i,j,d;
};

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%I64d",&s[i].fi),s[i].se=i;
    for (int i=1;i<=n;i++) scanf("%I64d",&t[i]);
}

ll getv(ll x)
{
    return t[x]-s[x].fi;
}

void process()
{
    sort(s+1,s+n+1);
    sort(t+1,t+n+1);
    stack<ll> st;
    vector<ds> ans;
    int check=1;
    for (int i=1;i<=n;i++)
        if (s[i].fi>t[i])
        {
            ll v=s[i].fi-t[i];
            while (!st.empty() && v)
            {
                ll tmp=min(getv(st.top()),v);
                s[st.top()].fi+=tmp;
                v-=tmp;
                ans.pb({s[st.top()].se,s[i].se,tmp});
                if (getv(st.top())==0) st.pop();
            }
            if (v)
            {
                check=0;
                break;
            }
        }
        else if (s[i].fi<t[i]) st.push(i);
    if (!st.empty()) check=0;
    if (check)
    {
        cout<<"YES"<<endl<<ans.size()<<endl;
        for (int i=0;i<ans.size();i++) printf("%I64d %I64d %I64d\n",ans[i].i,ans[i].j,ans[i].d);
    }
    else cout<<"NO";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}