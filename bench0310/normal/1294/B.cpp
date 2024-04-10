#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(),v.end());
        bool ok=1;
        for(int i=0;i<n-1;i++) if(v[i].second>v[i+1].second) ok=0;
        if(ok==0) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            int x=0,y=0;
            string res;
            for(int i=0;i<n;i++)
            {
                if(x<v[i].first) res+=string(v[i].first-x,'R');
                if(y<v[i].second) res+=string(v[i].second-y,'U');
                tie(x,y)=v[i];
            }
            cout << res << endl;
        }
    }
    return 0;
}