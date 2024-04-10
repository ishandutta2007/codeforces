#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        set<int> s;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        map<int,int> m;
        int id=1;
        for(int b:s) m[b]=id++;
        for(int i=1;i<=n;i++) a[i]=m[a[i]];
        vector<int> dp(n+1,0);
        vector<int> all(n+1,0);
        vector<int> last(n+1,0);
        vector<int> cnt(n+1,0);
        vector<int> now(n+1,0);
        vector<int> first(n+1,0);
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        for(int i=n;i>=1;i--) first[a[i]]=i;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=max(dp[last[a[i]]],now[a[i]-1])+1;
            if(now[a[i]-1]==cnt[a[i]-1]) dp[i]=max(dp[i],all[a[i]-1]+1);
            res=max(res,dp[i]);
            last[a[i]]=i;
            now[a[i]]++;
            if(now[a[i]]==cnt[a[i]]) all[a[i]]=dp[first[a[i]]]+cnt[a[i]]-1;
        }
        cout << n-res << endl;
    }
    return 0;
}