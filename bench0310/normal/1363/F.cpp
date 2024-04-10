#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    string s;
    int n;
    vector<array<int,26>> cnt;
    vector<array<int,26>> prv;
    obj(string t)
    {
        s=t;
        n=s.size();
        s="$"+s;
        cnt.resize(n+1);
        prv.resize(n+1);
        cnt[0].fill(0);
        prv[0].fill(-1);
        for(int i=1;i<=n;i++)
        {
            cnt[i]=cnt[i-1];
            cnt[i][s[i]-'a']++;
            prv[i]=prv[i-1];
            prv[i][s[i]-'a']=i;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        obj one(s);
        obj two(t);
        s="$"+s; t="$"+t;
        const int inf=(1<<30);
        vector<int> dp(n+1,inf);
        dp[n]=0;
        auto chmin=[&](int &a,int b){a=min(a,b);};
        for(int i=n;i>=1;i--)
        {
            vector<int> ndp(n+1,inf);
            for(int j=0;j<=n;j++)
            {
                if(two.prv[j][s[i]-'a']!=-1) chmin(ndp[two.prv[j][s[i]-'a']-1],dp[j]);
                if(one.cnt[i][s[i]-'a']<=two.cnt[j][s[i]-'a']) chmin(ndp[j],dp[j]+1);
            }
            dp=ndp;
        }
        int res=inf;
        for(int j=0;j<=n;j++) chmin(res,dp[j]);
        if(res==inf) res=-1;
        cout << res << "\n";
    }
    return 0;
}