#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int cnt[n+1];
    for(int o=1;o<=n;o++)
    {
        for(int i=0;i<(int)v[o].size();i++)
        {
            if(o<v[o][i]) v[o][i]-=o;
            else v[o][i]=n-(o-v[o][i]);
        }
        sort(v[o].begin(),v[o].end());
        if(!v[o].empty()) cnt[o]=((v[o].size()-1)*n+v[o][0]);
        else cnt[o]=0;
    }
    for(int o=1;o<=n;o++)
    {
        int res=cnt[o];
        int mv=0;
        for(int i=o+1;;i++)
        {
            mv++;
            if(i==n+1) i=1;
            if(i==o) break;
            res=max(res,(cnt[i]!=0)*(cnt[i]+mv));
        }
        cout << res << " ";
    }
    cout << endl;
    return 0;
}