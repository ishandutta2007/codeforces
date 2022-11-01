#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (30)
#define INF ((ll)1e16)

ll n,d[N][N],ans;
string s,t,res;

int main()
{
    cin>>s>>t>>n;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)d[i][j]=INF;
    for(int i=0;i<N;i++)d[i][i]=0;
    for(int i=0;i<n;i++)
    {
        char v,u;
        ll w;
        cin>>v>>u>>w;
        d[v-'a'][u-'a']=min(d[v-'a'][u-'a'],w);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
    if(s.size()!=t.size())return cout<<-1,0;
    for(int i=0;i<s.size();i++)
    {
        ll mini=INF,id;
        for(int j=0;j<N;j++)
            if(mini>d[s[i]-'a'][j]+d[t[i]-'a'][j])
                mini=d[s[i]-'a'][j]+d[t[i]-'a'][j],id=j;
        if(mini>=INF)return cout<<-1,0;
        ans+=mini,res+=(char)(id+'a');
    }
    cout<<ans<<"\n"<<res;
    return 0;
}