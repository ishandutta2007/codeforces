#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

#define TASK "test"

int main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    vector<vector<int>> ans;
    vector<int> cur(d,1);
    ans.push_back(cur);
    while(--n)
    {
        cur[0]++;
        int c=0;
        while(c!=d-1 && cur[c]>m) cur[c]=1,cur[++c]++;
        if(cur[d-1]>m)
        {
            cout<<-1<<endl;
            return 0;
        }
        ans.push_back(cur);
    }
        for(int j=0;j<d;j++)
    {
    for(int i=0;i<ans.size();i++)
            cout<<ans[i][j]<<' ';
        cout<<endl;
    }
 }