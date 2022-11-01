#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=205;
map<string,int> id;
vector<string> h={""};
int now=1;
vector<int> v[N];
vector<int> match;
vector<bool> vis(N,0);

void ini(string s)
{
    if(s.size()==4) return;
    for(char c='a';c<='z';c++)
    {
        s+=c;
        ini(s);
        id[s]=now++;
        h.push_back(s);
        s.pop_back();
    }
}

bool solve(int a)
{
    if(vis[a]==1) return 0;
    vis[a]=1;
    for(int to:v[a])
    {
        if(match[to]==-1||solve(match[to])==1)
        {
            match[to]=a;
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ini("");
    match.assign(h.size(),-1);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        for(int j=1;j<(1<<s.size());j++)
        {
            if(__builtin_popcount(j)>4) continue;
            string t;
            for(int k=0;k<(int)s.size();k++) if(j&(1<<k)) t+=s[k];
            v[i].push_back(id[t]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        vis.assign(n+1,0);
        solve(i);
    }
    vector<string> res(n+1,"");
    for(int i=1;i<(int)h.size();i++) if(match[i]!=-1) res[match[i]]=h[i];
    bool ok=1;
    for(int i=1;i<=n;i++) if(res[i].empty()) ok=0;
    if(ok)
    {
        for(int i=1;i<=n;i++) cout << res[i] << "\n";
    }
    else cout << "-1\n";
    return 0;
}