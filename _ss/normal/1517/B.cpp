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
const int N=1e3+10;
int n,m,a[N][N];
struct ds {int i,j,val;};

bool cmp(ds t1,ds t2) {return t1.val<t2.val;}

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
        vector<ds> vt;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) cin>>a[i][j],vt.pb({i,j,a[i][j]});
        sort(all(vt),cmp);
        vt.resize(m);
        for (int i=1;i<=m;i++)
        {
            int x=vt[i-1].i,y=vt[i-1].j;
            swap(a[x][y],a[x][i]);
            for (ds &p : vt)
                if (p.i==x && p.j==i) p.j=y;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++) cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}