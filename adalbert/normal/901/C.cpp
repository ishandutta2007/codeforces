#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".txt","r",stdin); freopen (name".txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=500000;

vector<int> vec[arr];
int mx[arr],use[arr],sum[arr],used[arr];;

vector<int> visited;

void dfs(int u, int pred)
{
    use[u]=1;
    used[u]=1;
    visited.pb(u);

    for (auto i:vec[u])
    {
        if (i==pred)
            continue;
        if (use[i])
        {
            int mxx=u;
            int mnx=u;
            int last=visited.size()-1;
            while (visited[last]!=i)
            {
                last--;
                mxx=max(mxx,visited[last]);
                mnx=min(mnx,visited[last]);
            }
            mx[mnx]=mxx;
        } else
        {
            if (!used[i])
            dfs(i,u);
        }
    }
    use[u]=0;
    visited.pop_back();
}

signed main()
{
    fast;
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    for (int i=1;i<=n;i++)
        mx[i]=n+1;

    for (int i=1;i<=n;i++)
        if (!used[i])
        {
            dfs(i,0);
        }



    for (int i=n-1;i>=1;i--)
        mx[i]=min(mx[i],mx[i+1]);

    for (int i=1;i<=n;i++)
        sum[i]=mx[i]+sum[i-1];

    cin>>m;
    while (m--)
    {
        int l,r;
        cin>>l>>r;
        int res=0;
        if (mx[l]>r+1)
        {
            //cout<<'!';
            res+=(r+1)*(r-l+1);
        } else
        {
            int left=l;
            int right=r;
            while (right-left>1)
            {
                int d=(right+left)/2;
                if (mx[d]<=r+1)
                    left=d; else
                    right=d;
            }
            if (mx[right]<=r+1)
            {
                left=right;
            }
            res+=sum[left]-sum[l-1];
            res+=(r-left)*(r+1);
        }

        res-=(r+l)*(r-l+1)/2;
        cout<<res<<'\n';
    }
}
/*
1
0 0 1
1 1
1 2
*/