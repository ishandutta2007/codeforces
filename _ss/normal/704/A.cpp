#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=3e5+10,msiz=2,mod=1e9+7,inf=1e18;
vector<int> li[maxn];
int ev[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,pr=1,t,x,sl=0,res=0;
    cin>>n>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>t>>x;
        if (t==1)
        {
            sl++;
            res++;
            ev[sl]=x;
            li[x].pb(sl);
        }
        else if (t==2)
        {
            for (int j=0;j<li[x].size();j++)
                if (ev[li[x][j]]) ev[li[x][j]]=0,res--;
            li[x].clear();
        }
        else
        {
            while (pr<=x)
            {
                if (ev[pr]) ev[pr]=0,res--;
                pr++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}