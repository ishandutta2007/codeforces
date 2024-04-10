#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;
map<string,int> cnt;
map<string,string> trace;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        set<string> scnt;
        for (int l=0;l<(int)s.size();l++)
            for (int r=l;r<(int)s.size();r++) scnt.insert(s.substr(l,r-l+1));
        for (auto it=scnt.begin();it!=scnt.end();it++) cnt[*it]++,trace[*it]=s;
    }
    int q;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        string s;
        cin>>s;
        int ans=cnt[s];
        if (ans) cout<<ans<<" "<<trace[s]<<"\n";
        else cout<<"0 -\n";
    }
    return 0;
}