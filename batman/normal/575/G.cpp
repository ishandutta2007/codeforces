#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (201*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll n,m,d[N],par[N],par_e[N],num[N];
vector <pair <ll,ll> > e[N];
vector <ll> v[N];

bool cmp(ll x,ll y)
{
    if(num[par[x]]!=num[par[y]])return num[par[x]]<num[par[y]];
    return par_e[x]<par_e[y];
}
bool equal_check(ll x,ll y){return !(num[par[x]]==num[par[y]] && par_e[x]==par_e[y]);}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll v,u,c;
        cin>>v>>u>>c;
        e[v].push_back({u,c});
        e[u].push_back({v,c});
    }
    queue <ll> q;
    v[1].push_back(n-1),q.push(n-1),d[n-1]=1,par[n-1]=-1;
    while(q.size())
    {
        ll x=q.front();
        q.pop();
        for(int i=0;i<e[x].size();i++)
            if(e[x][i].second==0 && !d[e[x][i].first])
                v[1].push_back(e[x][i].first),q.push(e[x][i].first),d[e[x][i].first]=1,par[e[x][i].first]=x;
    }
    for(int i=2;;i++)
    {
        for(int j=0;j<v[i-1].size();j++)
        {
            ll x=v[i-1][j];
            for(int k=0;k<e[x].size();k++)
            {
                if(!d[e[x][k].first])
                    v[i].push_back(e[x][k].first),d[e[x][k].first]=i,par[e[x][k].first]=x,par_e[e[x][k].first]=e[x][k].second;
                else if(d[e[x][k].first]==i && (num[x]<num[par[e[x][k].first]] || (num[x]==num[par[e[x][k].first]] && par_e[e[x][k].first]>e[x][k].second)))
                        par[e[x][k].first]=x,par_e[e[x][k].first]=e[x][k].second;
            }
        }
        if(!v[i].size())break;
        if(v[i].size()>1)sort(v[i].begin(),v[i].end(),cmp);
        num[v[i][0]]=0;
        for(int j=1;j<v[i].size();j++)
            num[v[i][j]]=num[v[i][j-1]]+equal_check(v[i][j],v[i][j-1]);
    }
    ll x=0;
    vector <ll> ans;
    string s="";
    while(x!=-1)
        ans.push_back(x),s=(char)(par_e[x]+'0')+s,x=par[x];
    ll i=0;
    while(s[i]=='0')i++;
    if(i==s.size())cout<<0;
    while(i<s.size())cout<<s[i++];
    cout<<"\n"<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" "; 
    
    return 0;
}