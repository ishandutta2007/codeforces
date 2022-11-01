#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> tin(N,0);
vector<int> tout(N,0);
int tcnt=1;

void dfs(int a,int p=-1)
{
    tin[a]=tcnt++;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
    }
    tout[a]=tcnt-1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> a(n);
    vector<int> b(n+1,0);
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i-1][0] >> b[i] >> c[i];
    for(int i=0;i<n;i++) a[i][1]=i+1;
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    vector<set<int>> s(2);
    for(int i=1;i<=n;i++) if(b[i]!=c[i]) s[b[i]].insert(tin[i]);
    auto sub=[&](int x,int id)->int
    {
        auto it=s[id].lower_bound(tin[x]);
        if(it==s[id].end()||(*it)>tout[x]) return -1;
        else return (*it);
    };
    ll res=0;
    if(s[0].size()!=s[1].size()) res=-1;
    else
    {
        for(auto [val,x]:a)
        {
            while(1)
            {
                int one=sub(x,0);
                int two=sub(x,1);
                if(one==-1||two==-1) break;
                s[0].erase(one);
                s[1].erase(two);
                res+=(2*val);
            }
        }
    }
    cout << res << "\n";
    return 0;
}