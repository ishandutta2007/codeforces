#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m;
vector<string> s(10);
string res;
vector<vector<bool>> vis(10,vector<bool>(1<<10,0));

void solve(int idx,int mask,string now)
{
    if(idx==m)
    {
        res=now;
        return;
    }
    if(vis[idx][mask]) return;
    vis[idx][mask]=1;
    string pos;
    for(int i=0;i<n;i++) pos+=s[i][idx];
    for(char c:pos)
    {
        int nxt=mask;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(c!=s[i][idx]&&(mask&(1<<i))>0) ok=0;
            if(c!=s[i][idx]) nxt|=(1<<i);
        }
        if(ok) solve(idx+1,nxt,now+c);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> s[i];
        res="-1";
        for(int i=0;i<10;i++) for(int j=0;j<(1<<10);j++) vis[i][j]=0;
        solve(0,0,"");
        cout << res << "\n";
    }
    return 0;
}