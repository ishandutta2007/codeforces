#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
const int inf=(1<<30);
const ll mod=1000000007;
vector<array<int,2>> v[N];
vector<int> d(N,inf);
vector<ll> res(N,-1);

void solve(vector<int> opt,int dist,ll val)
{
    if(opt.empty()) return;
    vector<int> go[10];
    vector<array<int,2>> tmp;
    for(int a:opt) for(auto [to,w]:v[a]) tmp.push_back({w,to});
    sort(tmp.begin(),tmp.end());
    for(auto [w,to]:tmp)
    {
        if(d[to]==dist+1&&res[to]==-1)
        {
            go[w].push_back(to);
            res[to]=(10*val+w)%mod;
        }
    }
    for(int c=0;c<=9;c++) solve(go[c],dist+1,(10*val+c)%mod);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int idx=n+1;
    auto add=[&](int a,int b,int w)
    {
        v[a].push_back({b,w});
    };
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        string s=to_string(i);
        int now=a;
        for(int j=0;j<(int)s.size();j++)
        {
            int nxt=b;
            if(j<(int)s.size()-1) nxt=idx++;
            add(now,nxt,s[j]-'0');
            now=nxt;
        }
        now=b;
        for(int j=0;j<(int)s.size();j++)
        {
            int nxt=a;
            if(j<(int)s.size()-1) nxt=idx++;
            add(now,nxt,s[j]-'0');
            now=nxt;
        }
    }
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    d[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        auto [da,a]=q.top();
        q.pop();
        if(d[a]<da) continue;
        for(array<int,2> tmp:v[a])
        {
            int to=tmp[0];
            if(d[a]+1<d[to])
            {
                d[to]=d[a]+1;
                q.push({d[to],to});
            }
        }
    }
    res[0]=0;
    solve({1},0,0);
    for(int i=2;i<=n;i++) cout << res[i] << "\n";
    return 0;
}