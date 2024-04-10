#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int query(vector<int> v)
{
    cout << "? " << v.size();
    for(int x:v) cout << " " << x;
    cout << endl;
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

int query(int l,int r)
{
    vector<int> v;
    for(int i=l;i<=r;i++) v.push_back(i);
    return query(v);
}

void solve(vector<int> v)
{
    cout << "!";
    for(int x:v) cout << " " << x;
    cout << endl;
    string s;
    cin >> s;
    if(s=="Incorrect") exit(0);
}

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<vector<int>> v(k);
        for(int i=0;i<k;i++)
        {
            int m;
            cin >> m;
            v[i].resize(m);
            for(int j=0;j<m;j++) cin >> v[i][j];
        }
        int m=query(1,n);
        int l=0,r=n;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(query(1,mid)==m) r=mid;
            else l=mid;
        }
        vector<int> res(k);
        for(int i=0;i<k;i++)
        {
            if(find(v[i].begin(),v[i].end(),r)!=v[i].end())
            {
                vector<bool> vis(n+1,0);
                for(int z:v[i]) vis[z]=1;
                vector<int> x;
                for(int j=1;j<=n;j++) if(vis[j]==0) x.push_back(j);
                res[i]=query(x);
            }
            else res[i]=m;
        }
        solve(res);
    }
    return 0;
}