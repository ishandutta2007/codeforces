#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD=1e9+7;

int powmod(int x,int p)
{
    if(p==0) return 1;
    if(p==1) return x;
    int T=powmod(x,p/2);
    if(p%2) return x*T%MOD*T%MOD;
    else return T*T%MOD;
}

main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> in(n);
    for(int i=0;i<n;i++)
        cin>>in[i];
    int to[10]={0,1,2,3,4,5,6,7,8,9};
    int le[10]={1,1,1,1,1,1,1,1,1,1};
    for(int i=n-1;i>=0;i--)
    {
        int L=0;
        int C=0;
        for(int j=3;j<in[i].size();j++)
        {
            C=(C*powmod(10,le[in[i][j]-'0'])+to[in[i][j]-'0'])%MOD;
            L=(L+le[in[i][j]-'0'])%(MOD-1);
        }
        to[in[i][0]-'0']=C;
        le[in[i][0]-'0']=L;
    }
    int ans=0;
    for(int i=0;i<s.size();i++)
        if(to[s[i]-'0']+1) ans=(ans*powmod(10,le[s[i]-'0'])+to[s[i]-'0'])%MOD;
    cout<<ans<<endl;
}