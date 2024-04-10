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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> res;
        auto mex=[&](int id)
        {
            res.push_back(id+1);
            vector<bool> x(n+1,0);
            for(int b:a) x[b]=1;
            for(int i=0;i<=n;i++)
            {
                if(x[i]==0)
                {
                    a[id]=i;
                    break;
                }
            }
            //for(int i=0;i<n;i++) cout << a[i] << " \n"[i==n-1];
        };
        vector<int> cnt(n+1,0);
        for(int x:a) cnt[x]++;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]!=n&&cnt[a[i]]==1) continue;
            cnt[a[i]]--;
            mex(i);
            cnt[a[i]]++;
        }
        for(int i=0;i<n;i++) if(a[i]==n) mex(i);
        //cout << "done\n";
        int now=a[n-1];
        if(a[n-1]!=n) mex(n-1);
        while(1)
        {
            bool ok=1;
            for(int i=0;i<n-1;i++) ok&=(a[i]<=a[i+1]);
            if(ok==1) break;
            if(now==n-1)
            {
                for(int j=0;j<n-1;j++) if(a[j]!=j) now=j;
            }
            int nxt=a[now];
            mex(now);
            now=nxt;
        }
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}