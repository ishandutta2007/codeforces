#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=3e5+10;
int k[N],c[N],n,m;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>k[i];
        sort(k+1,k+n+1);
        for (int i=1;i<=m;i++) cin>>c[i];
        priority_queue<int,vi,greater<int>> q;
        int j=1;
        ll res=0;
        for (int i=1;i<=n;i++)
        {
            while (j<=k[i])
            {
                q.push(c[j]);
                j++;
            }
            q.push(c[k[i]]);
            res+=q.top();
            q.pop();
        }
        cout<<res<<"\n";
    }
    return 0;
}