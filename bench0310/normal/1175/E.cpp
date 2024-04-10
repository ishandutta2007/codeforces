#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    const int N=500000;
    vector<int> add[N+1];
    vector<int> rm[N+1];
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin >> l >> r;
        add[r].push_back(r);
        rm[l].push_back(r);
    }
    vector<vector<int>> mv(N+1,vector<int>(18,0));
    for(int i=0;i<=N;i++) for(int j=0;j<18;j++) mv[i][j]=i;
    multiset<int> s;
    for(int i=N;i>=0;i--)
    {
        for(int a:add[i]) s.insert(a);
        if(s.empty()) continue;
        mv[i][0]=(*s.rbegin());
        for(int j=1;j<18;j++) mv[i][j]=mv[mv[i][j-1]][j-1];
        for(int a:rm[i]) s.erase(s.find(a));
    }
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        int res=0;
        for(int j=17;j>=0;j--)
        {
            if(mv[l][j]>=r) continue;
            l=mv[l][j];
            res+=(1<<j);
        }
        if(mv[l][0]>=r) cout << res+1 << "\n";
        else cout << "-1\n";
    }
    return 0;
}