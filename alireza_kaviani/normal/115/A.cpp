#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

vector<int> adj[2005];
int dfs(int x,int p=-1)
{
    int a=0;
    for(int u:adj[x])
    {
        if(u!=p)
        {
            a=max(a,dfs(u,x));
        }
    }
    return a+1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int v;
        cin >> v;
        v--;
        if(v!=-2)
        {
            adj[v].push_back(i);
        }
        else
        {
            a.push_back(i);
        }
    }

    int ans=0;
    for(int i:a)
    {
        ans=max(ans,dfs(i));
    }
    cout << ans << endl;

    return 0;
}