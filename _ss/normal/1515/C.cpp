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
const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,x;
        cin >> n >> m >> x;
        priority_queue<pii, vector<pii>, greater<pii> > q;
        for (int i=1;i<=m;i++) q.push(mp(0,i));
        cout<<"YES\n";
        for (int i=1,x;i<=n;i++)
        {
            cin>>x;
            pii p = q.top();
            cout<<p.se<<" ";
            p.fi+=x;
            q.pop();
            q.push(p);
        }
        cout<<"\n";
    }
    return 0;
}